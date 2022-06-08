#include "stm32f4xx.h"
#include <stdint.h>

#define GPIOAEN					(1U<<0)
#define UART2EN					(1U<<17)

#define	SYS_FREQ 				16000000
#define APB1_CLK				SYS_FREQ
#define UART_BAUDRATE			115200

#define CR1_TE					(1U<<3)

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BoudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BoudRate);

int main(void)
{


	while(1)
	{

	}
}

void uar2_tx_init(void)
{
	/*configure uart gpio pin */
	//enable clock access to gpioa
	RCC->AHB1ENR |= GPIOAEN;
	//set PA2 mode to alternate function mode
	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |=  (1U<<5);
	//set PA2 alternate function type to UART_TX (AFO7)
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &= ~(1U<<11);



	/*configure uart module*/
	//enable clock access to uart2
	RCC->APB1ENR |= UART2EN;
	//configure uart boud rate
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE);
	//configure the transfer direction
	USART2->CR1 = CR1_TE;
	//ENABLE UART MODULE
}

//to set boudrate
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BoudRate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk,BoudRate);
}

//calculating baud rate
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BoudRate)
{
	return((PeriphCLK + (BoudRate/2U))/BaudRate);
}
