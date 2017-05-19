#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>

#define RAM 1000000000
#define STATS 1000
static uint16_t *lengths;
static uint32_t *stat;	//histogramm of lengths

int main(int argc, char** argv)
{
    if(argc != 3)
    {
     printf("please enter a valid number and a file name");
     printf("usage: collatz [count] [output file]");
     exit(0);
    }
    
    lengths = malloc(RAM * sizeof(*lengths));
    stat = malloc(STATS * sizeof(*stat));
    
    uint64_t max = atol(argv[1]);
    uint64_t step = max/100;
    
    uint32_t max_l = 0;
    
    for(uint64_t i = 1; i < max; i++)
    {
        if(i % step == 0) 
            printf("%d%%\n", i/step);
        
        uint64_t x = i;
        uint16_t l = 0;
        
        while(x > 1)
        {          
            l++;
            
            if(x & 1)
                x = 3*x+1;
            else
                x /= 2;
	    
	    if(x < i && x < RAM)
	    {
	      l += lengths[x];
	      break;
	    }
        }
        
        if(i < RAM)
	  lengths[i] = l;
	if(l < STATS)
	stat[l]++;   
	
	if(l > max_l)
	  max_l = l;
    }
    
    FILE *file = fopen(argv[2], "w");
    
    for(int i = 0; i < STATS; i++)
       fprintf(file, "%d\n", stat[i]);
    
    fclose(file);    
    
    printf("Done, Max. Length: %d\n", max_l);
}
