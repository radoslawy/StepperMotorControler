#include <stdio.h>
#include "pico/stdlib.h"

int main(){

    //Initialise I/O
    stdio_init_all(); 
		
		gpio_init(25);

    gpio_init(13); // resolution
    gpio_init(12); // resolution
    gpio_init(11); // resolution

    gpio_init(10); // Dir

    gpio_init(0); // Step 

    gpio_set_dir(13, GPIO_OUT);	// res
    gpio_set_dir(12, GPIO_OUT); // res
    gpio_set_dir(11, GPIO_OUT); // res
    gpio_set_dir(10, GPIO_OUT); // dir
    gpio_set_dir(0, GPIO_OUT);	// step 
		gpio_set_dir(25, GPIO_OUT);

		gpio_put(25,1);

		int res = 0;
		int dir = 0;

    while(1){
			printf(" Res = %d, Dir = %d \n", res, dir);
			printf("Set Res & Dir: \n");
			scanf("%d %d", &res, &dir);
			printf(" Res = %d, Dir = %d \n", res, dir);
			
			if (dir==0) 
				{gpio_put(10,0);}
			else if (dir==1)
				{gpio_put(10,1);}
			else 
			{gpio_put(10,0);
			 printf("WRONG DIR\n");}

     	switch (res) {
  
			case 0: // full
			{gpio_put(11 ,0);
     	gpio_put(12 ,0);
     	gpio_put(13 ,0);}	
    	break;
  
			case 1: // 1/2
    	{gpio_put(11 ,1);
     	gpio_put(12 ,0);
     	gpio_put(13 ,0);}	
    	break;
	
			case 2: // 1/4
    	{gpio_put(11 ,0);
     	gpio_put(12 ,1);
     	gpio_put(13 ,0);}	
    	break;
	
			case 3: // 1/8
    	{gpio_put(11 ,1);
     	gpio_put(12 ,1);
     	gpio_put(13 ,0);}	
    	break;
	
			case 4: // 1/16
   		{gpio_put(11 ,0);
   	  gpio_put(12 ,0);
   	  gpio_put(13 ,1);}	
   		break;

			case 5: // 1/32
   	  {gpio_put(11 ,1);
   	  gpio_put(12 ,0);
   	  gpio_put(13 ,1);}	
   	 	break;

  		default:
  	  {gpio_put(11 ,1);
    	 gpio_put(12 ,0);
     	 gpio_put(13 ,1);
			 printf("WRONG Res\n");}	
		}
   gpio_put(0, 1); // Set pin 0 to high
        printf("Step!\n");
        sleep_ms(500); // 0.5s delay
        gpio_put(0, 0); // Set pin 0 to low
				printf("stepus \n");
        sleep_ms(500); // 0.5s delay
				res = 5;
				dir = 0;
				printf("reset \n");
		}
}
