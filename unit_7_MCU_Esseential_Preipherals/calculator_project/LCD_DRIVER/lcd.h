/*
 * lcd.h
 *
 * Created: 9/30/2023 8:38:09 AM
 *  Author: Abdullah Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "../platform_types.h"
#include "../bit_obr.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*SIMULATION CONNECT IN DB0--->DB7 IN PORTA & CTRL PINS CONNECT IN PINS PORTB1, PORTB2, PORTB3---->RS, R/W, EN*/
#define LCD_PORT_VALUE PORTA			 // take value 1 for HIGH and value zero for LOW, look at TRM atmega32 page 50 and table 20
#define LCD_PORT_DIRECTION DDRA			 // take value 1 for output and value zero for input, look at TRM atmega32 page 50 and table 20
#define LCD_CTRL_PORT_VALUE PORTB		 // take value 1 for HIGH and value zero for LOW, look at TRM atmega32 page 50 and table 20
#define LCD_CTRL_PORT_DIRECTION DDRB	 // take value 1 for output and value zero for input, look at TRM atmega32 page 50 and table 20

#define ENABLE 1
#define RW     2
#define RS     3
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Because LCD has 2 Mode*/
#define EIGHT_BIT_MODE		8
#define FOUR_BIT_MODE       4
#define ACTIVE_MODE 8
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Useful symbolic names for LCD commands*/
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)
#define LCD_MOVE_CURSOR_TO_THE_HOME_POSITION        (0x02)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/********************************* APIs *********************************/
void LCD_INIT_FUNC();
void LCD_SEND_COMMAND_FUNC(uint8_t command);
void LCD_SEND_CHAR_FUNC(uint8_t data);
void LCD_SET_CURSOR_FUNC(uint8_t line, uint8_t col);
void LCD_BUSY_FUNC();
void LCD_CLEAR_SCREEN_FUNC();
void LCD_ENABLE_PULSE_FUNC();
void LCD_SEND_STRING_FUNC(char* string);
void LCD_DISPLAY_NUMBER_FUNC(int n);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif /* LCD_H_ */