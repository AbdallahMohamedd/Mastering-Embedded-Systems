/*
 * lcd.h
 *
 * Created: 9/28/2023 5:48:57 AM
 *  Author: Abdullah Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../platform_types.h"
#include "../bit_obr.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*SIMULATION CONNECT IN DB0--->DB7 IN PORTA & CTRL PINS CONNECT IN PINS PORTB1, PORTB2, PORTB3---->RS, R/W, EN*/
#define LCD_PORT_VALUE PORTA			 // take value 1 for HIGH and value zero for LOW, look at TRM atmega32 page 50 and table 20
#define LCD_PORT_DIRECTION DDRA			 // take value 1 for output and value zero for input, look at TRM atmega32 page 50 and table 20 
#define LCD_CTRL_PORT_VALUE PORTB		 // take value 1 for HIGH and value zero for LOW, look at TRM atmega32 page 50 and table 20
#define LCD_CTRL_PORT_DIRECTION DDRB	 // take value 1 for output and value zero for input, look at TRM atmega32 page 50 and table 20
#define ENABLE 3
#define RW     2
#define RS     1
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Because LCD has 2 Mode*/
#define EIGHT_BIT_MODE		8			
#define FOUR_BIT_MODE       4
#define ACTIVE_MODE EIGHT_BIT_MODE
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
void LCD_Init();
void LCD_Send_Command(uint8 command);
void LCD_Send_Char(uint8 data);
void LCD_Send_String(char* string);
void LCD_Cursor_XY(uint8 line, uint8 col);
void LCD_Busy();
void LCD_Clear_Screen();
void ENABLE_PULSE();
void LCD_display_number(int n);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* LCD_H_ */