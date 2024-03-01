#include <stdio.h>
#include "pico/stdlib.h"

int main(){

    //Initialise I/O
    stdio_init_all(); 

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



	char UserInput;


		gpio_put(10, 1); // dir

    while(1){
			
			printf("Set Res: \n");

			UserInput = getchar();

     	switch (UserInput) {
  
			case '0': // full
			{gpio_put(11 ,0);
     	gpio_put(12 ,0);
     	gpio_put(13 ,0);}	
    	break;
  
			case '1': // 1/2
    	{gpio_put(11 ,1);
     	gpio_put(12 ,0);
     	gpio_put(13 ,0);}	
    	break;
	
			case '2': // 1/4
    	{gpio_put(11 ,0);
     	gpio_put(12 ,1);
     	gpio_put(13 ,0);}	
    	break;
	
			case '3': // 1/8
    	{gpio_put(11 ,1);
     	gpio_put(12 ,1);
     	gpio_put(13 ,0);}	
    	break;
	
			case '4': // 1/16
   		{gpio_put(11 ,0);
   	  gpio_put(12 ,0);
   	  gpio_put(13 ,1);}	
   		break;

			case '5': // 1/32
   	  {gpio_put(11 ,1);
   	  gpio_put(12 ,0);
   	  gpio_put(13 ,1);}	
   	 	break;

  		default:
  	  {gpio_put(11 ,1);
    	 gpio_put(12 ,0);
     	gpio_put(13 ,1);}	
		}
   gpio_put(0, 1); // Set pin 0 to high
        printf("Step!\n");
        sleep_ms(500); // 0.5s delay
        gpio_put(0, 0); // Set pin 0 to low
				printf("stepus \n");
        sleep_ms(500); // 0.5s delay
    

		}
}
