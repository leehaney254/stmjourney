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
//PERIPHERAL ENABLE
#define AHB1EN_R_OFFSET			(0x30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
//MODE REGISTER
#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))
//OUTPUT DATA REGISTER
#define OD_R_OFFSET				(0X14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN					(1U<<0)
#define PIN5					(1U<<5)
#define LED_PIN					PIN5


int main()
{
	//enable clock access to GPIOA
	RCC_AHB1EN_R |= GPIOAEN;
	//set PA5 as general purpose output
	GPIOA_MODE_R |= (1U<<10);
	GPIOA_MODE_R &= ~(1u<<11);

	while(1)
	{
		//set PA5 high
//		GPIOA_OD_R |= LED_PIN;
	    GPIOA_OD_R ^= LED_PIN;
	    for(int i=0; i<100000; i++){}
	}
}


