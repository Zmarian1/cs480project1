#include "util.h"
#include <string.h>
#include <unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>

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

	int ifFileSend = 0; //Checks for additional file argument
	struct config config;
	
	char* filename=NULL;
	if(argc>1)
		filename=strtok(argv[1]," "); //grab filename
	if(filename!=NULL)//if filename grabbed
		ifFileSend=true;//set file send to true

	init_config(&config, argc, argv);
	int sending = 1;

	bool sequence[8] = {1,0,1,0,1,0,1,1};

	if(ifFileSend) { // Sends file
		int file;
		int fds[2];
		pipe(fds);
		if(fork()==0){//fork first child parent waits
			if(fork()==0){
				close(1);//close normal stdout
				dup(fds[1]);//stdout
				close(fds[0]);
				//cat file
				
				int   file;
				char  buffer[512];
				int   read_size;
				file = open(filename, O_RDONLY);
				if (file == -1)
				{
					fprintf(stderr, "Error: %s: file not found\n", argv[1]);
				        return (-1);
				}
				while ((read_size = read(file, buffer, 512)) > 0){
					write(1, &buffer, read_size);
				}
				write(1,"exit\n",6);
				close(file);
				wait(NULL);
				return (0);
			}
			
			else{
				sleep(.1);
				close(0);   // close normal stdin
	     	   		dup(fds[0]);   // make stdin same as fds[0]
	     	   		close(fds[1]); // unused write end
			
			}
		}
		else{
			wait(NULL);
			return 0;
		}
	}

	if(!ifFileSend)
		printf("Please type a message (exit to stop).\n");
	else
		printf("Sending File %s\n",filename);
	while (sending) {

		// Get a message to send from the user
		if(!ifFileSend){
			printf("< ");
			char text_buf[128];
			fgets(text_buf, sizeof(text_buf), stdin);

			// Indicate termination if input message is "exit"
			if (strcmp(text_buf, "exit\n") == 0) {
				sending = 0;
			}
			if(ifFileSend)
				printf("%s",text_buf);
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
		else{
			
			//char* sent=strtok(text_buf,"«");
			while(sending){
				char text_buf[128];
				fgets(text_buf, sizeof(text_buf), stdin);
				// Indicate termination if input message is "exit"
				if (strcmp(text_buf, "exit\n") == 0) {
					sending = 0;
					break;
				}
				if(ifFileSend)
					printf("%s",text_buf);
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
				//if(sent)
				//	*sent=0;
				//sent=strtok(&text_buf[1],"«");
			}
		
		}

	}
	printf("Sender finished\n");
	return 0;
}











