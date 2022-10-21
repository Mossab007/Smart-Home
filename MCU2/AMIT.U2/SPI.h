/*
 * SPI.h
 *
 * Created: 12/19/2021 4:23:59 PM
 *  Author: Mossab
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void SPI_Master_Init (void);

void SPI_Slave_Init (void);

void SPI_Master_Init_Trans(void);

void SPI_Master_Ter_Trans (void);

uint8 SPI_Transiever(uint8 data);




#endif /* SPI_H_ */