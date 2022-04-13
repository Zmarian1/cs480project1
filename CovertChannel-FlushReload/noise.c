#include <util.h>

// a function to make accesses to memory at specified address
void access_mem(ADDR_PTR addr)
{
    asm volatile ("mov (%0), %%rax\n"
        :
        : "c" (addr)
        : "rax");
}

// adding noise to the covert channel
// done by running another executable (noise) on the same core as the sender 
// this program makes accesses to the same shared memory as the sender and reciever 
// these accesses act as noise for when the receiever is listening to the sender
int main(int argc, char **argv) {
    // set up configuration
    struct config config;
    init_config(&config, argc, argv);
    //printf("shared file name is: %s\n", config.sharedFileName);
    int inFile = open(config.sharedFileName, O_RDONLY); // the file that the the sender and reciever share
	if(inFile == -1) {
		printf("Failed to Open File\n");
		exit(1);
	}


	void *mapaddr = mmap(NULL,DEFAULT_FILE_SIZE,PROT_READ,MAP_SHARED,inFile,0);

    int end_of = mapaddr + lseek(inFile, -1, SEEK_END); // address for end of the file from current offset 
    //printf("file cur offset: %i\n", mapaddr);
    //printf("file end offset: %i\n", end_of);

    int j = 0;
    sleep(10);
    for(int k = 0; k < 5; k++){
        for(uint64_t i = config.addr; j < 4096; j += 10){
            ADDR_PTR newAddr = (ADDR_PTR) mapaddr + j;
            access_mem(newAddr); // access some memory 
            uint32_t time = measure_one_block_access_time(newAddr); //measure time to acess memory
            // printf("time taken to access location %i: %i\n", newAddr, time);
        }
    }
    // Sync with sender
	CYCLES start_t = cc_sync();
	while ((get_time() - start_t) < config.interval) {
		
		CYCLES access_time = measure_one_block_access_time(config.addr); 
		for(uint64_t i = config.addr; j < 4096; j += 10){
            ADDR_PTR newAddr = (ADDR_PTR) mapaddr + j;
            access_mem(newAddr); // access some memory 
            uint32_t time = measure_one_block_access_time(newAddr); //measure time to acess memory
            // printf("time taken to access location %i: %i\n", newAddr, time);
        }
	}

    
    // access_mem(config.addr);
    // uint32_t timehere = measure_one_block_access_time(config.addr);
    //printf("time taken to access location : %i\n", timehere);
    return 0;
}