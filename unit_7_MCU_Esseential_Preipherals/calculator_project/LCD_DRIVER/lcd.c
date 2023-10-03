/*
 * lcd.c
 *
 * Created: 9/30/2023 8:37:59 AM
 *  Author: Abdullah Mohamed
 */ 


#include "lcd.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_INIT_FUNC()
{
	_delay_ms(20);
	/*INITTIALIZE LCD TO CLEAR SCREEN, LOOK AT TRM IN PAGES 8 AND 28*/
	/*Make ENABLE, RS AND RW AS OUTPUT AND GIVE THEM ZERO VALUE*/
	LCD_CTRL_PORT_DIRECTION |=  ((1 << RS) | (1 << RW) | (1 << ENABLE));   //Set all CTRL bits as output
	LCD_CTRL_PORT_VALUE     &= ~((1 << RS) | (1 << RW) | (1 << ENABLE));  //Give them zero value
	
	_delay_ms(15);
	#if ACTIVE_MODE == EIGHT_BIT_MODE
	LCD_PORT_DIRECTION = 0xff; //Set all LCD PORT "PORTA" as an output
	LCD_CLEAR_SCREEN_FUNC();
	LCD_SEND_COMMAND_FUNC(LCD_MOVE_CURSOR_TO_THE_HOME_POSITION);
	LCD_SEND_COMMAND_FUNC(LCD_FUNCTION_8BIT_2LINES);
	#elif ACTIVE_MODE == FOUR_BIT_MODE
	LCD_PORT_DIRECTION = 0xf0; //Set all LCD PORT "PORTA" as an output
	LCD_CLEAR_SCREEN_FUNC();
	LCD_SEND_COMMAND_FUNC(LCD_MOVE_CURSOR_TO_THE_HOME_POSITION);
	LCD_SEND_COMMAND_FUNC(LCD_FUNCTION_4BIT_2LINES);
	#endif
		
	LCD_SEND_COMMAND_FUNC(LCD_ENTRY_MODE);
	LCD_SEND_COMMAND_FUNC(LCD_BEGIN_AT_FIRST_ROW);
	LCD_SEND_COMMAND_FUNC(LCD_DISP_ON_CURSOR_BLINK);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_BUSY_FUNC()
{
	/*Make PORTA as an input ---> DDRA = 0b0000 0000*/
	LCD_PORT_DIRECTION = 0x00;

	
	/*RE-SET RS, SET RW and enable pulse*/
	RESET_BIT(LCD_CTRL_PORT_VALUE,RS);
	SET_BIT(LCD_CTRL_PORT_VALUE,RW);
	LCD_ENABLE_PULSE_FUNC();
	
	/*Make PORTA as an output*/
	#if ACTIVE_MODE == EIGHT_BIT_MODE
	LCD_PORT_DIRECTION = 0xff;
	#elif ACTIVE_MODE == FOUR_BIT_MODE
	LCD_PORT_DIRECTION = 0xf0;
	#endif
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_ENABLE_PULSE_FUNC()
{
	/*RESET EN ---> DELAY --> SET EN*/
	RESET_BIT(LCD_CTRL_PORT_VALUE,ENABLE);
	_delay_ms(50);
	SET_BIT(LCD_CTRL_PORT_VALUE,ENABLE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_CLEAR_SCREEN_FUNC()
{
	/*Clear return counter to zero*/
	LCD_SEND_COMMAND_FUNC(LCD_CLEAR_SCREEN);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_SEND_COMMAND_FUNC(uint8 command)
{
	/*Check Busy ---> RESET RS and RW ---> set LCD PORT = COMMAND*/
	
	/*Check Busy*/
	//LCD_Busy();
	
	/*RESET RS and RW*/
	//RS = 0 ---> to take Instruction
	//RW = 0 ---> to write on screen, choose 0 not 1 because we don't need Read any data from LCD poat
	RESET_BIT(LCD_CTRL_PORT_VALUE,RW);
	RESET_BIT(LCD_CTRL_PORT_VALUE,RS);
	
	/*set LCD PORT = COMMAND*/
	#if ACTIVE_MODE == EIGHT_BIT_MODE
	LCD_PORT_VALUE = command;
	LCD_ENABLE_PULSE_FUNC();
	#elif ACTIVE_MODE == FOUR_BIT_MODE
	LCD_PORT_VALUE = (command & 0xf0);
	LCD_ENABLE_PULSE_FUNC();
	
	RESET_BIT(LCD_CTRL_PORT_VALUE,RW);
	RESET_BIT(LCD_CTRL_PORT_VALUE,RS);
	LCD_PORT_VALUE = (command << 4);
	LCD_ENABLE_PULSE_FUNC();
    #endif
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_SEND_CHAR_FUNC(uint8 data)
{
		/*Check Busy ---> RESET RW, SET RS---> set LCD PORT = COMMAND*/
		
		/*Check Busy*/
		//LCD_Busy();
		
		/*RESET RW*/
		//RS = 1 ---> to take Instruction
		//RW = 0 ---> to write on screen, choose 0 not 1 because we don't need Read any data from LCD poat
		RESET_BIT(LCD_CTRL_PORT_VALUE,RW);
		SET_BIT(LCD_CTRL_PORT_VALUE,RS);
		
		/*set LCD PORT = DATA*/
		#if ACTIVE_MODE == EIGHT_BIT_MODE
		LCD_PORT_VALUE = data;
		LCD_ENABLE_PULSE_FUNC();
		#elif ACTIVE_MODE == FOUR_BIT_MODE
		LCD_PORT_VALUE = (data & 0xf0);
		LCD_ENABLE_PULSE_FUNC();
		
		RESET_BIT(LCD_CTRL_PORT_VALUE,RW);
		SET_BIT(LCD_CTRL_PORT_VALUE,RS);
		LCD_PORT_VALUE = (data << 4);
		LCD_ENABLE_PULSE_FUNC();
		#endif	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_SEND_STRING_FUNC(char* string)
{
	int counter = 0;
	while(*string > 0)
	{
		counter++;
		LCD_SEND_CHAR_FUNC(*string++);
		if(counter == 16)
		LCD_SET_CURSOR_FUNC(1,0);
		else if(counter == 33)
		{
			LCD_CLEAR_SCREEN_FUNC();
			LCD_SET_CURSOR_FUNC(0,0);
			counter = 0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_SET_CURSOR_FUNC(uint8_t line, uint8_t col)
{
	if(line == 0)
	{
		if(col < 16 && col >=0)
		LCD_SEND_COMMAND_FUNC(LCD_BEGIN_AT_FIRST_ROW + col);
	}
	else if(line == 1)
	{
		if(col < 16 && col >=0)
		LCD_SEND_COMMAND_FUNC(LCD_BEGIN_AT_SECOND_ROW + col);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_DISPLAY_NUMBER_FUNC(int n)
{
	char int_to_string[10];
	sprintf(int_to_string,"%d",n);
	LCD_SEND_STRING_FUNC(int_to_string);
}





