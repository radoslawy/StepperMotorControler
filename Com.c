#include "stdio.h"
#include "pico/stdlib.h"


#define STEP 1
#define DIR 2

int arr[3]={0,0,0};


int main() {

stdio_init_all();

gpio_set_dir(STEP, GPIO_OUT);
gpio_set_dir(DIR, GPIO_OUT);
gpio_set_dir(3, GPIO_OUT);
gpio_set_dir(4, GPIO_OUT);
gpio_set_dir(5, GPIO_OUT);

gpio_put(STEP, 0);

while(true) {
	printf("SYNTAX TESTOWY #stepnum #dir #stepsize 1-6 \n:");
	for(int i=0;i<3;i++) {
		arr[i]=getchar()-'0';
	}
	
	
	switch (arr[2])
	{
		default:
			gpio_put(3,0);
			gpio_put(4,0);
			gpio_put(5,0);
			break;
		case 2:
			gpio_put(3,1);
			gpio_put(4,0);
			gpio_put(5,0);
			break;
		case 3:
			gpio_put(3,0);
			gpio_put(4,1);
			gpio_put(5,0);
			break;

		case 4:
			gpio_put(3,1);
			gpio_put(4,1);
			gpio_put(5,0);
			break;
		case 5:
			gpio_put(3,0);
			gpio_put(4,0);
			gpio_put(5,1);
			break;
		case 6:
			gpio_put(3,0);
			gpio_put(4,1);
			gpio_put(5,1);
			break;

	}

	if (arr[1]==1) {
		gpio_put(DIR, 1);
	}
	else gpio_put(DIR, 0);

	for(int i=0;i<=arr[0];i++) {
	gpio_put(STEP, 1);
	sleep_ms(500);
	}
	gpio_put(STEP, 0);
}
}
