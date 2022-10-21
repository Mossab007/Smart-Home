/*
 * UART.h
 *
 * Created: 29/08/2021 06:13:51 
 *  Author: Mossab
 */ 


#ifndef UART_H_
#define UART_H_

#include "DIO.h"

void UART_Init(void);

void UART_SendByte(uint8 );

void UART_SendString(uint8* str);

uint8 UART_ReceiveByte(void);

uint8* UART_ReceiveString(void);



#endif /* UART_H_ */