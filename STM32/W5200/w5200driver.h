#ifndef __SPI2_H
#define __SPI2_H

#include <stdint.h>

typedef enum
{
	WizNotBusy = 0x00,
	WizSend = 0x01,
}WIZ_RW_Status_Typedef;

void Init_W5200Driver(void); //Инициализация драйвера
uint8_t Eth_GetInterrupt(void); //Ножка прерывания nINT
void Eth_Reset(uint8_t State); //Сброс устройства
void Eth_RW_SPI(uint8_t* Buffer, uint16_t Length); // Запуск DMA для передачи/приема по SPI
WIZ_RW_Status_Typedef Eth_Busy(void); //Проверка занятости цикла прием - передача

#endif

