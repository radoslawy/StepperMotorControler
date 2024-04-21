#include <stdio.h>
#include "pico/stdlib.h"


void setRes (){
		printf("set res (0-5): ");
		int res = getchar()-48;
		printf("\n res: %d\n",res);
		switch (res) {
  
			case 0: // full
			{gpio_put(11 ,0);
     	gpio_put(12 ,0);
     	gpio_put(13 ,0);
			printf("res full \n");}
    	break;
  
			case 1: // 1/2
    	{gpio_put(11 ,1);
     	gpio_put(12 ,0);
     	gpio_put(13 ,0);	
			printf("res 1/2 \n");}
    	break;
	
			case 2: // 1/4
    	{gpio_put(11 ,0);
     	gpio_put(12 ,1);
     	gpio_put(13 ,0);	
			printf("res 1/4 \n");}
    	break;
	
			case 3: // 1/8
    	{gpio_put(11 ,1);
     	gpio_put(12 ,1);
     	gpio_put(13 ,0);
			printf("res 1/8 \n");}
    	break;
	
			case 4: // 1/16
   		{gpio_put(11 ,0);
   	  gpio_put(12 ,0);
   	  gpio_put(13 ,1);
			printf("res 1/16 \n");}
   		break;

			case 5: // 1/32
   	  {gpio_put(11 ,1);
   	  gpio_put(12 ,0);
   	  gpio_put(13 ,1);	
			printf("res 1/32 \n");}
   	 	break;

  		default:
  	  {gpio_put(11 ,1);
    	 gpio_put(12 ,0);
     	gpio_put(13 ,1);
			printf("RES def \n");}	
		}
}

void setup(){

    //Initialise I/O
    stdio_init_all(); 

    gpio_init(13); // resolution
    gpio_init(12); // resolution
    gpio_init(11); // resolution

		gpio_init(1); // Const

    gpio_init(10); // Dir

    gpio_init(0); // Step 

    gpio_set_dir(13, GPIO_OUT);	// res
    gpio_set_dir(12, GPIO_OUT); // res
    gpio_set_dir(11, GPIO_OUT); // res
    gpio_set_dir(10, GPIO_OUT); // dir
    gpio_set_dir(0, GPIO_OUT);	// step 
		gpio_set_dir(1, GPIO_OUT); // CONSt

		gpio_put(1,1); //CONST ON
		gpio_put(10, 1); // dir
}

void setDir(){

	printf("Set Dir (1 or 0): ");
	int dir = getchar()-48;
	printf("dir %d\n",dir);
	if (dir != 0 && dir != 1){
		dir = 0;
		printf("wrong dir\n");
	}

	gpio_put(10,dir);
}

int setRep(){
	int rep=1;
	printf("Rep: ");
	scanf("%i",&rep);
	printf("%d\n",rep);
	return rep;
}

int main(){

	setup(); // initialize pins

	getchar(); // wait for first input

	int rep=1;

  while(1){

		rep=setRep();
		setRes();
		setDir();

     
		for(int i=1;i<=rep;i++)
		{
   			gpio_put(0, 1); // Set pin 0 to high
        printf("Step!\n");
        sleep_ms(500); // 0.5s delay
        gpio_put(0, 0); // Set pin 0 to low
				printf("stepus \n");
        sleep_ms(500); // 0.5s delay
				printf("rep %d z %d\n", i, rep);
  	}
		}
}

