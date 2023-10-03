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
#include "../../platform_types.h"
#include "../bit_obr.h"


#define KPAD_PORT_VALUE PORTC
#define KPAD_PORT_DIRECTION DDRC
#define KPAD_PORT_PIN PINC


#define R0 0
#define R1 1
#define R2 2
#define R3 3 
#define C0 4
#define C1 5 
#define C2 6 
#define C3 7

/********************************* APIs *********************************/
void KPAD_INIT();
char KPAD_GET_CHAR();


#endif /* KPAD_H_ */