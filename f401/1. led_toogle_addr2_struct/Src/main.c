#include <stdint.h>
//Peripheral base
#define PERIPH_BASE 			(0x40000000UL)
//WHERE THE PERIPHERAL ADDRESS BEGINS
#define AHB1PERIPH_OFFSET		(0X00020000UL)
#define AHB1PERIPH_BASE         (PERIPH_BASE + AHB1PERIPH_OFFSET)
//GPIOA ADDRRESSING
#define GPIOA_OFFSET 			(0x0000UL)
#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET)
//RCC OFFSET
#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOAEN					(1U<<0)
#define PIN5					(1U<<5)
#define LED_PIN					PIN5


typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t DUMMY[4];			//used as a place holder for the registers in between
	volatile uint32_t ODR;
}GPIO_TypeDef;

typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;
}RCC_TypeDef;

#define RCC 	((RCC_TypeDef*) RCC_BASE)			//type casting the struct to the base
#define GPIOA	((GPIO_TypeDef*) GPIOA_BASE)


int main()
{
	//enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//set PA5 as general purpose output
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1u<<11);

	while(1)
	{
		//set PA5 high
		GPIOA->ODR ^= LED_PIN;
		for(int i=0;i<100000; i++){}
	}
}


