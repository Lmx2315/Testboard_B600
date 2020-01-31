#include "stm32f10x.h"
#include "w5200driver.h"
#include "w5200.h"
#include "gpio_init.h"
#include "bitbanding.h"

#define WIZ_CS_PORT	GPIOD
#define WIZ_CS_PIN	7

#define WIZ_INT_PORT	GPIOD
#define WIZ_INT_PIN		4

#define WIZ_RES_PORT	GPIOD
#define WIZ_RES_PIN		2

#define WIZ_PWDN_PORT	GPIOD
#define WIZ_PWDN_PIN		3

#define LOW 0
#define HIGH 1

WIZ_RW_Status_Typedef RWProcess = WizNotBusy;
CallBack_Typedef CallBack = 0;

void WIZ_CS(uint8_t val)
{
	if(val)
		WIZ_CS_PORT->BSRR = 1 << WIZ_CS_PIN;
	else
	{
		while (SPI3->SR & SPI_SR_BSY);
		WIZ_CS_PORT->BRR = 1 << WIZ_CS_PIN;
	}
}

void Eth_RW_SPI(uint8_t* Buffer, uint16_t Length)
{
	if(Length)
	{
		RWProcess = WizSend; //Флаг, что начался прием-передача данных
		__memory_changed();
		WIZ_CS(LOW);
		BIT_BAND_PER(DMA2_Channel2->CCR, DMA_CCR2_EN) = 0;		//Отключили DMA
		BIT_BAND_PER(DMA2_Channel1->CCR, DMA_CCR1_EN) = 0;
		DMA2_Channel1->CMAR = (uint32_t)Buffer;								//Указатель на буфер
		DMA2_Channel2->CMAR = (uint32_t)Buffer;
		DMA2_Channel1->CNDTR = Length;												//Длина буфера
		DMA2_Channel2->CNDTR = Length;
		BIT_BAND_PER(DMA2_Channel1->CCR, DMA_CCR1_EN) = 1;		//Запуск
		BIT_BAND_PER(DMA2_Channel2->CCR, DMA_CCR1_EN) = 1;
	}
}

void DMA2_Channel1_IRQHandler(void)
{
	if(DMA2->ISR & DMA_ISR_TCIF1)
	{
		WIZ_CS(HIGH);
		RWProcess = WizNotBusy; //Устанавливаем "Завершено"
	}
	DMA2->IFCR = DMA_IFCR_CGIF1;
}

WIZ_RW_Status_Typedef Eth_Busy(void)
{
	return RWProcess;
}

uint8_t Eth_GetInterrupt(void)
{
	return !(WIZ_INT_PORT->IDR & (1 << WIZ_INT_PIN));
}

void Eth_Reset(uint8_t State)
{
	if(State)
	{
		WIZ_RES_PORT->BSRR = 1 << WIZ_RES_PIN;
		WIZ_PWDN_PORT->BRR = 1 << WIZ_PWDN_PIN;
	}
	else
	{
		WIZ_PWDN_PORT->BSRR = 1 << WIZ_PWDN_PIN;
		WIZ_RES_PORT->BRR = 1 << WIZ_RES_PIN;
	}
}

void Init_W5200Driver(void)
{
	DMA2->ISR = DMA_ISR_GIF1 | DMA_ISR_TCIF1;
	NVIC_EnableIRQ(DMA2_Channel1_IRQn);
}
