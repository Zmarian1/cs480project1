#include "util.h"

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
	char* fileSendMSG = NULL;
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
		char** new_argv = malloc((argc-1) * sizeof *new_argv);
		int new_argc = argc - 2;
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
		//printf("\n%s", file_buf);

		init_config(&config, new_argc, new_argv);
	} else {
		init_config(&config, argc, argv);
	}

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
		
		// size_t msg_len = strlen(msg);
		// for (int ind = 0; ind < msg_len; ind++) {
		// 	if (msg[ind] == '0') {
		// 		send_bit(false, &config);
		// 	} else {
		// 		send_bit(true, &config);
		// 	}
		// }
	}

	char msg_ch[MAX_BUFFER_LEN + 1];

	uint32_t bitSequence = 0;
	uint32_t sequenceMask = ((uint32_t) 1<<6) - 1;
	uint32_t expSequence = 0b101011;
	
	printf("Listening...\n");
	fflush(stdout);
	while (1) {
		bool bitReceived = detect_bit(&config);

		// Detect the sequence '101011' that indicates sender is sending a message	
		bitSequence = ((uint32_t) bitSequence<<1) | bitReceived;
		if ((bitSequence & sequenceMask) == expSequence) {
			int binary_msg_len = 0;
			int strike_zeros = 0;
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
			msg_ch[binary_msg_len - 8] = '\0';

			// Print out message
			int ascii_msg_len = binary_msg_len / 8;
			char msg[ascii_msg_len];
			printf("> %s\n", conv_char(msg_ch, ascii_msg_len, msg));

			if(ifFileSend) {
				size_t length = strlen(msg_ch)+1;
        		fileSendMSG = malloc(length);
        		memcpy(fileSendMSG, msg_ch, length);
			}
	
			// Terminate loop if received "exit" message
			if (strcmp(msg, "exit") == 0) {
				break;
			}
		}
	}

	if(ifFileSend) {
		int correctBits = 0;
		int totalBits = 0;
		//for(int i = 0; i < strlen(source); i++) {

		//}
		printf("\nERROR RATE: %d correct bits out of %d total bits\n", correctBits, totalBits);
		//printf("\n\nTHE SENT FILE WAS: %s", fileSendMSG);

	}

	printf("Receiver finished\n");
	return 0;
}


