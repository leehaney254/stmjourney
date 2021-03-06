#include "stm32f4xx.h"


#define GPIOAEN 		(1U<<0)
#define GPIOCEN 		(1U<<2)						//used to enable clock in port C


#define PIN5 			(1U<<5)
#define PIN13			(1U<<13)

#define LED_PIN			PIN5
#define BTN_PIN			PIN13

int main(void)
{
	//enable clock acces to GPIOA and GPIOC
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	//set PA% as output
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	//set PC13 as input pin
	GPIOC->MODER &= ~(1u<<26);
	GPIOC->MODER &= ~(1u<<27);

	while(1)
	{
		//CHECK IF BUTTON IS PRESSED
		if(GPIOC->IDR & BTN_PIN)
		{
			//turn on led
			GPIOA->BSRR = LED_PIN;
		}
		else
		{
			//turn off led
			GPIOA->BSRR = (1U<<21);
		}
	}
}
