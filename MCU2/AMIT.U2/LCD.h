/*
 * LCD.h
 *
 * Created: 09/10/2021 11:52:04 
 *  Author: Mossab
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Cfg.h"
#define F_CPU  16000000
#include <util/delay.h>


void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_WriteChar(uint8 chr);

void LCD_WriteString(uint8* str);

void LCD_Goto(uint8 row, uint8 col);

void LCD_Clear(void);

void LCD_WriteInteger(sint32 intgr);

#endif /* LCD_H_ */