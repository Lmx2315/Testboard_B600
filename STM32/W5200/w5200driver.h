#ifndef __SPI2_H
#define __SPI2_H

#include <stdint.h>

typedef enum
{
	WizNotBusy = 0x00,
	WizSend = 0x01,
}WIZ_RW_Status_Typedef;

void Init_W5200Driver(void); //������������� ��������
uint8_t Eth_GetInterrupt(void); //����� ���������� nINT
void Eth_Reset(uint8_t State); //����� ����������
void Eth_RW_SPI(uint8_t* Buffer, uint16_t Length); // ������ DMA ��� ��������/������ �� SPI
WIZ_RW_Status_Typedef Eth_Busy(void); //�������� ��������� ����� ����� - ��������

#endif

