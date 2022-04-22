#include <iostream>
#include <cstdlib>
#include <x86intrin.h>



int main(int argc, char**argv){
    #define SIZE (1<<22)

    unsigned long long *rand = (unsigned long long *)malloc(SIZE*sizeof(unsigned long long));
    unsigned long long *seed = (unsigned long long *) malloc(SIZE*sizeof(unsigned long long));

    for (int i = 0; i < SIZE; i++) {
      while (!_rdrand64_step(&rand[i]))
          ;
    }

    for (int i = 0; i < SIZE; i++) {
      while (!_rdseed64_step(&seed[i]))
          ;
    }
    return 0;

}