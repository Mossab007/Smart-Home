/*
 * UART.c
 *
 * Created: 29/08/2021 06:13:10 
 *  Author: Mossab
 */ 


#include "UART.h"


void UART_Init(void)
{
	uint32 BR_Value = 0;
	
	DIO_SetPinDir(DIO_PORTD ,DIO_PIN0, DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTD ,DIO_PIN1, DIO_PIN_OUTPUT);
	
	UCSRB |= 0x18 ;
	UCSRC |= 0x86 ;
	
	BR_Value = ((80000) / (16 * (96))) - 1;
	
	UBRRL =  BR_Value ;
	
}

void UART_SendByte(uint8 data)
{
	
	UDR = data;
	
	while(GET_BIT(UCSRA , 5) == 0);
	
}

void UART_SendString(uint8* str)
{
	
 uint8 i = 0;
 
 while(str[i] != '\0')
 {
	 UART_SendByte(str[i]);
	 i++;
 }
 
}

uint8 UART_ReceiveByte(void)
{
	uint8 data = 0;
	
	while(GET_BIT(UCSRA , 7) == 0);
	
	data = UDR ;
	
	return data ;
}