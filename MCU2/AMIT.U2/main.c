/*
 * AMIT.U2.c
 *
 * Created: 12/20/2021 10:12:55 PM
 * Author : Mossab
 */ 

#include "SPI.h"
#include "LED.h"
#include "LCD.h"

#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
    uint8 rec_data=0;
    uint8 trans_data=1;
    
    LED0_inti();
    LCD_Init();
    SPI_Slave_Init();
	
	
    while (1) 
    {
		rec_data=SPI_Transiever(trans_data);
		
		if (rec_data=='1')
		{
			LCD_Goto(0,4);
			LCD_WriteString("WELCOME");
			_delay_ms(200);
			LED0_ON();
			LCD_Clear();
			LCD_WriteString("LIGHTS ON");
			
			
		}
		else if (rec_data=='2')
		{
			LED0_OFF();
			LCD_Clear();
			LCD_WriteString("LIGHTS OFF");
			_delay_ms(500);
			LCD_Clear();
			
		}
		
		else
		{
			LCD_Clear();
			LCD_WriteString("error");
			_delay_ms(600);
			LCD_Clear();
		}
		
		rec_data=0;
		_delay_ms(1000);
		
    }
}

