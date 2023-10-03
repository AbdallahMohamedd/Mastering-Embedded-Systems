/*
 * kpad.h
 *
 * Created: 9/30/2023 6:07:24 AM
 *  Author: Abdullah Mohamed
 */ 


#ifndef KPAD_H_
#define KPAD_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "../platform_types.h"
#include "../bit_obr.h"


#define KPAD_COL_PORT_VALUE PORTC
#define KPAD_COL_PORT_DIRECTION DDRC
#define KPAD_COL_PORT_PIN PINC
#define C0 0
#define C1 1
#define C2 2
#define C3 3
#define C4 4
#define C5 5

#define KPAD_ROW_PORT_VALUE PORTD
#define KPAD_ROW_PORT_DIRECTION DDRD
#define KPAD_ROW_PORT_PIN PIND
#define R0 0
#define R1 1
#define R2 2
#define R3 3 

/********************************* APIs *********************************/
void KPAD_INIT_FUNC();
char KPAD_GET_CHAR();


#endif /* KPAD_H_ */