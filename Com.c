#include "stdio.h"
#include "pico/stdlib.h"


#define STEP 1
#define DIR 2

int arr[2]={0,0}; // tylko kierunek i rozdzielczosc


int main() {

stdio_init_all();

//ustawiam uzywane piny

gpio_set_dir(STEP, GPIO_OUT);
gpio_set_dir(DIR, GPIO_OUT);
gpio_set_dir(3, GPIO_OUT);
gpio_set_dir(4, GPIO_OUT);
gpio_set_dir(5, GPIO_OUT);

gpio_put(STEP, 0);

//do komunikacji tylko 2 wartosci kierunek i rozdzielczosci
//dalej idzie z raspberki info zwrone "gotowe" i wysylana jest konfiguracja kolejnego
//przykladowo info z komputera 11 11 11 to beda 3 kroki kierunek 1 rozdzielczosc 1
//komputer wysyla kolejny kro dopiero po infomacji zwrotnej


while(true) {
	printf("SYNTAX TESTOWY #dir #stepsize 1-6 \n:");
	for(int i=0;i<2;i++) {
		arr[i]=getchar()-'0';
	}
	
//Ustawiam piny do wielksci kroku	
	switch (arr[1])
	{
		default:
			gpio_put(3,0);
			gpio_put(4,0);
			gpio_put(5,0);
			break;
			printf("\n step size 1");
		case 2:
			gpio_put(3,1);
			gpio_put(4,0);
			gpio_put(5,0);
			break;
			printf("\n step size 1/2");
		case 3:
			gpio_put(3,0);
			gpio_put(4,1);
			gpio_put(5,0);
			break;
			printf("\n step size 1/4");

		case 4:
			gpio_put(3,1);
			gpio_put(4,1);
			gpio_put(5,0);
			break;
			printf("\n step size 1/8");
		case 5:
			gpio_put(3,0);
			gpio_put(4,0);
			gpio_put(5,1);
			break;
			printf("\n step size 1/16");
		case 6:
			gpio_put(3,0);
			gpio_put(4,1);
			gpio_put(5,1);
			break;
			printf("\n step size 1/32");

	}
	//Ustawiam kierunek
	if (arr[0]==1) {
		gpio_put(DIR, 1);
		printf("DIR 1");
	}
	else {gpio_put(DIR, 0); printf("\nDIR 2");}

	//po ustawieniu kierunku i rozdzielczosci wykonuje kroku

	gpio_put(STEP, 1);
	sleep_ms(500);
	printf("\nSTEPPING");
	gpio_put(STEP, 0);
	printf("GOTOWE");//tu info ze komputer moze wyslac dane kolejnego kroku
}
}
