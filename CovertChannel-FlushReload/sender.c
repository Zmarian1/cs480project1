#include "util.h"
#include <string.h>
#include <unistd.h>


void send_bit(bool one, struct config *config)
{
	// Synchronize with receiver
	CYCLES start_t = cc_sync();
	if (one) {
		
		ADDR_PTR addr = config->addr;
		while ((get_time() - start_t) < config->interval) {
			clflush(addr);
		}	

	} else {
	
		while (get_time() - start_t < config->interval) {}
	}
}

int main(int argc, char **argv) { // Append to end of arguments " -s filename"
	//TODO Error for argc < 2
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

	int sending = 1;

	bool sequence[8] = {1,0,1,0,1,0,1,1};

	char *str = NULL; // Entire file contents

	if(ifFileSend) { // Sends file
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
		//printf("\n\nFull file is: %s\n", str);

		// START OF SENDING CODE

		char *msg = string_to_binary(str);

		for (int i = 0; i < 8; i++) {
			send_bit(sequence[i], &config);
		}

		size_t msg_len = strlen(msg);
		for (int ind = 0; ind < msg_len; ind++) {
			if (msg[ind] == '0') {
				send_bit(false, &config);
			} else {
				send_bit(true, &config);
			}
		}

		exit(1);
	}

	printf("Please type a message (exit to stop).\n");
	while (sending) {
		// Get a message to send from the user
		printf("< ");
		char text_buf[128];
		fgets(text_buf, sizeof(text_buf), stdin);

		// Indicate termination if input message is "exit"
		if (strcmp(text_buf, "exit\n") == 0) {
			sending = 0;
		}

		// Convert that message to binary
		char *msg = string_to_binary(text_buf);

		// Send a '10101011' bit sequence tell the receiver
		// a message is going to be sent
		for (int i = 0; i < 8; i++) {
			send_bit(sequence[i], &config);
		}

		
		size_t msg_len = strlen(msg);
		for (int ind = 0; ind < msg_len; ind++) {
			if (msg[ind] == '0') {
				send_bit(false, &config);
			} else {
				send_bit(true, &config);
			}
		}

	}

	printf("Sender finished\n");
	return 0;
}