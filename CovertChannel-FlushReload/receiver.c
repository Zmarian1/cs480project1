#include "util.h"
#include <time.h>
#include<sys/wait.h>
// Cache miss latency threshold
int CACHE_MISS_LATENCY = 100;


bool detect_bit(struct config *config)
{
	int misses = 0;
	int hits = 0;

	// Sync with sender
	CYCLES start_t = cc_sync();
	while ((get_time() - start_t) < config->interval) {
		
		CYCLES access_time = measure_one_block_access_time(config->addr); 

		
		if (access_time > CACHE_MISS_LATENCY) {
			misses++;
		} else {
			hits++;
		}
	}

	return misses >= hits;
}

int main(int argc, char **argv) { // Append to end of arguments " -s filename"
	//TODO Error for argc < 2
	setbuf(stdout, NULL);

	FILE *fptr = fopen("bandwidth.txt", "a");

	char* fileSendMSG = NULL; // Message from channel
	char* originalMSG = NULL; // Message direct from file

	clock_t start, end;
    	double cpu_time_used; // Time keeping

	int ifFileSend = 0; //Checks for additional file argument
	char* filename=NULL;
	
	if(argc>1)
		filename=strtok(argv[1]," "); //grab filename
	if(filename!=NULL)//if filename grabbed
		ifFileSend=true;//set file send to true

	// Initialize config and local variables
	struct config config;
	
	init_config(&config, argc, argv);
	/*
	char *str = NULL; // Entire file contents
	
	if(ifFileSend) { // Grabs file for comparison (converts to binary)
		char buf[4096];
    	ssize_t n;
	    size_t len = 0;
		int file;
		file = open(file_buf, O_RDONLY);
    	while (n = read(file, buf, sizeof buf)) {
        	if (n < 0) {
            	if (errno == EAGAIN)
                	continue;
            	perror("read");
            	break;
        	}
        	str = realloc(str, len + n + 1);
        	memcpy(str + len, buf, n);
        	len += n;
        	str[len] = '\0';
    	}

		// Binary Conversion

		originalMSG = string_to_binary(str);
	}
	*/

	char msg_ch[MAX_BUFFER_LEN + 1];

	uint32_t bitSequence = 0;
	uint32_t sequenceMask = ((uint32_t) 1<<6) - 1;
	uint32_t expSequence = 0b101011;
	printf("Listening...\n");
	fflush(stdout);
	if(ifFileSend){
		if(fork()==0){
			int FDout=open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0777);//open output
			close(1);//close stdout
			dup(FDout);//set stdout to file input
			close(FDout);
		}
		else{
			wait(NULL);
			printf("File %s received\n",filename);
			return 0;
		}
	}
	
	while (1) {
		bool bitReceived = detect_bit(&config);

		// Detect the sequence '101011' that indicates sender is sending a message	
		bitSequence = ((uint32_t) bitSequence<<1) | bitReceived;
		if ((bitSequence & sequenceMask) == expSequence) {
			// Could combine buffers since length smaller
			int binary_msg_len = 0;
			int strike_zeros = 0;
			start = clock();
			for (int i = 0; i < MAX_BUFFER_LEN; i++) {
				binary_msg_len++;

				if (detect_bit(&config)) {
					msg_ch[i] = '1';
					strike_zeros = 0;
				} else {
					msg_ch[i] = '0';
					if (++strike_zeros >= 8 && i % 8 == 0) {
						break;
					}
				}
			}
			end = clock();
			msg_ch[binary_msg_len - 8] = '\0';

			// Print out message
			int ascii_msg_len = binary_msg_len / 8;
			char msg[ascii_msg_len];
			
			char* str = conv_char(msg_ch, ascii_msg_len, msg);
			//int strsize=sizeof &str / sizeof str;
			/*
			int newline="«";
			printf("%s\n", str);
			printf("%s\n", strtok(str,"«"));
			char* index=strchr(str,newline);
			printf("%s\n", strtok(index,"«"));
			*index=0;
			index=strchr(str,newline);
			printf("%s\n", strtok(index,"«"));
			while(index!=NULL){
				printf("%s\n", strtok(index,"«"));
				index=strchr(index,newline);
				
			}
			*/
			char* token = strtok(str, "«");
			    // Keep printing tokens while one of the
			    // delimiters present in str[].
			    while (token != NULL) {
				printf("%s\n", token);
				token = strtok(NULL, "«");
			    }
			break;
			/*
			if(ifFileSend) {
				size_t length = strlen(msg_ch)+1;
        		fileSendMSG = malloc(length);
        		memcpy(fileSendMSG, msg_ch, length);
				break;
			}
			*/
			// Terminate loop if received "exit" message
			
		}
	}

	if(ifFileSend) {
		char *str = NULL;
		char buf[4096];
    	ssize_t n;
	    size_t len = 0;
		int file;
		file = open(filename, O_RDONLY);
    	while (n = read(file, buf, sizeof buf)) {
        	if (n < 0) {
            	if (errno == EAGAIN)
                	continue;
            	perror("read");
            	break;
        	}
        	str = realloc(str, len + n + 1);
        	memcpy(str + len, buf, n);
        	len += n;
        	str[len] = '\0';
    	}

		// Binary Conversion

		originalMSG = string_to_binary(str);

		char* shortestString = originalMSG;

		double stringSize = 0; // Used over cast of strlen()
		for (char character = *shortestString; character != '\0'; character = *++shortestString) {
			stringSize++;
		}
		fprintf(fptr, "\nLengths are %d\n", strlen(originalMSG));
		//printf("\n\nTHE SENT FILE WAS: %s", fileSendMSG);

		stringSize = (int) strlen(originalMSG);

		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		double bandwidth = stringSize / cpu_time_used;
		//printf("\nERROR RATE: %d correct bits out of %d total bits\n", correctBits, strlen(originalMSG));
		fprintf(fptr, "BANDWIDTH: %f bits per second\n", bandwidth);
		fclose(fptr);
	}
	if(!ifFileSend)
		printf("Receiver finished\n");
	return 0;
}


