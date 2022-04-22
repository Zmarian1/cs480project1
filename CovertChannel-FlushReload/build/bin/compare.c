#include <sys/stat.h>
#include <sys/types.h>
#include <cstdio>
#include <cstddef>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int compareFiles(FILE *fp1, FILE *fp2,int len)
{
    // fetching character of two file
    // in two variable ch1 and ch2
    char ch1 = getc(fp1);
    char ch2 = getc(fp2);
  
    // error keeps track of number of errors
    // pos keeps track of position of errors
    // line keeps track of error line
    int error = 0;
  
    // iterate loop till end of file

    while (len>0)
    {
    	len--;
        // if both variable encounters new
        // line then line variable is incremented
        // and pos variable is set to 0
        //printf("%c %c\n",ch1,ch2);
	if(ch2==EOF){
		error+=len;
		len=0;
	}
	else{
		if (ch1!=ch2){// if fetched data is not equal then
            		error++;// error is incremented
        	}
        }
  	
        // if fetched data is not equal then
        // error is incremented
       
        
        // fetching character until end of file
        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }
  
    return error;
}
int main(int argc, char *argv[]){
    int comp;
    comp=atoi(argv[1]);
    int bandwidth;
    printf("Compareing %d times\n",comp);
    int errors=0,totalerrors=0;
    long filelen=0;
    float percent=0;
    FILE *fp2;
    FILE * band;
    char * band_input = NULL;
    size_t len = 0;
    ssize_t read;
    int lowest=-1;
    int lowest_band=0;
    band = fopen("bandwidth.txt", "r");
    if (band == NULL)
        exit(EXIT_FAILURE);
    char FileNo_tens;
    char FileNo_ones;
    // opening both file in read only mode
    FILE *fp1 = fopen("test.txt", "r");
    char ch1;
    	ch1 = getc(fp1);
    	while (ch1 != EOF){
    		ch1 = getc(fp1);
    		filelen++;
    	}
    	fclose(fp1);
    char output[]="outputXX.txt";
    int tens;
    int ones;
    for(int index=0; index<comp;index++){
    	fp1 = fopen("test.txt", "r");
    	ones=index%10;
    	FileNo_ones=ones+'0';
    	tens=index/10;
    	
    	FileNo_tens=tens+'0';

    	output[6]=FileNo_tens;
    	output[7]=FileNo_ones;
    	fp2 = fopen(output, "r");
    	
    	if (fp2 == NULL){
       		printf("Error : Files not open %s\n",output);
       		exit(0);
    	}
    	printf("Comparing file %s\n",output);
        read = getline(&band_input, &len, band);
        bandwidth=atoi(band_input);
    	errors=compareFiles(fp1, fp2,filelen);
    	if(errors>0){
    		percent+=((float)errors/filelen)*100;
    		totalerrors+=errors;
    		
    	}
    	printf("File %s had %d errors\n",output,errors);
        printf("Total Bandwidth %d\n",bandwidth);
        if(lowest>0){
            if(errors<lowest){
                lowest=errors;
                lowest_band=bandwidth;
            }
        }
        else{
            lowest=errors;
            lowest_band=bandwidth;
        }
    	fclose(fp2);
    	 fclose(fp1);

    }
    // closing both file
    printf("File Length %d\n",filelen);
    printf("Total Errors %d\n",totalerrors);
    percent/=comp;
    fclose(band);
    printf("Error rate of %.2f percent\n",percent);
    float lowest_rate;
    lowest_rate=((float)lowest/filelen)*100;
    printf("Lowest error rate of %.2f with band with %d\n",lowest_rate,lowest_band);
    return 0;
}

