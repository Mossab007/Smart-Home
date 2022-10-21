/*
 * AMIT.U1.c
 *
 * Created: 12/20/2021 9:55:54 PM
 * Author : Mossab 
 */ 

#define F_CPU 8000000
#include "UART.h"
#include "SPI.h"

#include <util/delay.h>


int main(void)
{
	
	uint8 data=0;
	uint8 rec_data=0;
	
	UART_Init();
	
	SPI_Master_Init();
	
	SPI_Master_Init_Trans();
	
	_delay_ms(1000);
	
    while (1) 
    {
	    data=UART_ReceiveByte();
		
		if(data)
		{
			rec_data=SPI_Transiever(data);
			data=0;
		}
	
	}
}

