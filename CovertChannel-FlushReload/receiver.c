#include "util.h"
#include <time.h>

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

	char* fileSendMSG = NULL; // Message from channel
	char* originalMSG = NULL; // Message direct from file

	clock_t start, end;
    double cpu_time_used; // Time keeping

	int ifFileSend = 0; //Checks for additional file argument
	int k = 0;
	while (k < argc) {
		if(strcmp(argv[k],"-s") == 0) {
			ifFileSend = 1;
		}
		k++;
	}

	// Initialize config and local variables
	struct config config;
	
	char file_buf[128];

	if(ifFileSend) { //Grabs additional file argument
		
		//char** new_argv = malloc((argc-1) * sizeof *new_argv);
		//int new_argc = argc - 2;
		
		/*
		for(int i = 0; i < new_argc; i++) {
			size_t length = strlen(argv[i])+1;
        	new_argv[i] = malloc(length);
        	memcpy(new_argv[i], argv[i], length);
		}
		new_argv[new_argc] = NULL;
		
		strcpy(file_buf, argv[argc - 1]);

		int k = 0;
		while(k < new_argc) {
			printf("%s ", new_argv[k]);
			k++;
		}
		//
		*/
		char* file_name=strtok(argv[0], " ");
		printf("\n%s", file_name);
		
		//init_config(&config, new_argc, new_argv);
		init_config(&config, argc, argv);
		
	} else {
		init_config(&config, argc, argv);
	}

	char *str = NULL; // Entire file contents
	/*
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
		int FDout=open("ouput.txt", O_WRONLY|O_CREAT);//open output
		close(1);//close stdout
		dup(FDout);//set stdout to file output
		close(FDout);
	
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
			printf("> %s\n", conv_char(msg_ch, ascii_msg_len, msg));

			if(ifFileSend) {
				size_t length = strlen(msg_ch)+1;
        		fileSendMSG = malloc(length);
        		memcpy(fileSendMSG, msg_ch, length);
				break;
			}
	
			// Terminate loop if received "exit" message
			if (strcmp(msg, "exit") == 0) {
				break;
			}
		}
	}

	if(ifFileSend) {
		/*
		int correctBits = 0;
		//printf("\n%s", fileSendMSG);
		//printf("\n%s", originalMSG);

		char* longestString = NULL; //Used so there won't be two for loops, avoids seg fault
		char* shortestString = NULL;

		if(strlen(fileSendMSG) > strlen(originalMSG)) {
			shortestString = originalMSG;
			longestString = fileSendMSG;
		} else {
			shortestString = fileSendMSG;
			longestString = originalMSG;
		}

		double stringSize = 0; // Used over cast of strlen()
		char character2 = *longestString;
		for (char character = *shortestString; character != '\0'; character = *++shortestString) {
    		if(character == character2) {
				correctBits++;
			}
			stringSize++;
			character2 = *++longestString;
		}

		//printf("\nLengths are %d and %d\n", strlen(originalMSG), strlen(fileSendMSG));
		//printf("\n\nTHE SENT FILE WAS: %s", fileSendMSG);

		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		double bandwidth = stringSize / cpu_time_used;
		printf("\nERROR RATE: %d correct bits out of %d total bits\n", correctBits, strlen(originalMSG));
		printf("BANDWIDTH: %f bits per second\n", bandwidth);
		*/
	}

	printf("Receiver finished\n");
	return 0;
}


