/*
 * lcd.c
 *
 * Created: 9/28/2023 5:48:47 AM
 *  Author: Abdullah Mohamed
 */ 


#include "lcd.h"
//static uint8 Counter = 0; 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_Init()
{
	/*Make delay as there is in TRM in pages 45 and 46*/ 
	_delay_ms(20);
	
	/*INITTIALIZE LCD TO CLEAR SCREEN, LOOK AT TRM IN PAGES 8 AND 28*/
	/*Make ENABLE, RS AND RW AS OUTPUT AND GIVE THEM ZERO VALUE*/
	LCD_CTRL_PORT_DIRECTION |=  ((1 << RS) | (1 << RW) | (1 << ENABLE));   //Set all CTRL bits as output
	LCD_CTRL_PORT_VALUE     &= ~((1 << RS) | (1 << RW) | (1 << ENABLE));  //Give them zero value
	
	_delay_ms(15);

	#if ACTIVE_MODE == EIGHT_BIT_MODE
	LCD_PORT_DIRECTION = 0xff; //Set all LCD PORT "PORTA" as an output
	LCD_Clear_Screen();
	LCD_Send_Command(LCD_MOVE_CURSOR_TO_THE_HOME_POSITION);
	LCD_Send_Command(LCD_FUNCTION_8BIT_2LINES);
	#elif ACTIVE_MODE == FOUR_BIT_MODE
	LCD_PORT_DIRECTION = 0xf0; //Set all LCD PORT "PORTA" as an output
	LCD_Clear_Screen();
	LCD_Send_Command(LCD_MOVE_CURSOR_TO_THE_HOME_POSITION);
	LCD_Send_Command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_Send_Command(LCD_ENTRY_MODE);         
	LCD_Send_Command(LCD_BEGIN_AT_FIRST_ROW);     
	LCD_Send_Command(LCD_DISP_ON_CURSOR_BLINK);   
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_Busy()
{
	/*Make PORTA as an input ---> DDRA = 0b0000 0000*/
	LCD_PORT_DIRECTION = 0x00;

	
	/*RE-SET RS, SET RW and enable pulse*/
	RESET_BIT(LCD_CTRL_PORT_VALUE,RS);
	SET_BIT(LCD_CTRL_PORT_VALUE,RW);
	ENABLE_PULSE();
	
	/*Make PORTA as an output*/
	#if ACTIVE_MODE == EIGHT_BIT_MODE
	LCD_PORT_DIRECTION = 0xFF;
	#elif ACTIVE_MODE == FOUR_BIT_MODE
	LCD_PORT_DIRECTION = 0xF0;
	#endif
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ENABLE_PULSE()
{
	/*RESET EN ---> DELAY --> SET EN*/
	RESET_BIT(LCD_CTRL_PORT_VALUE,ENABLE);
	_delay_ms(50);
	SET_BIT(LCD_CTRL_PORT_VALUE,ENABLE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_Clear_Screen()
{
	/*Clear return counter to zero*/
	LCD_Send_Command(LCD_CLEAR_SCREEN);
	//Counter= 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_Send_Command(uint8 command)
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
	ENABLE_PULSE();
	#elif ACTIVE_MODE == FOUR_BIT_MODE
	LCD_PORT_VALUE = (command & 0xf0) ;
	ENABLE_PULSE();
	
	RESET_BIT(LCD_CTRL_PORT_VALUE,RW);
	RESET_BIT(LCD_CTRL_PORT_VALUE,RS);
	LCD_PORT_VALUE =  (command << 4);
	ENABLE_PULSE();
	#endif	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_Send_Char(uint8 data)
{
	/*Check Busy*/
	//LCD_Busy();
	
	RESET_BIT(LCD_CTRL_PORT_VALUE,RW);	
    SET_BIT(LCD_CTRL_PORT_VALUE,RS);

	/*set LCD PORT = data*/
	#if ACTIVE_MODE == EIGHT_BIT_MODE
	LCD_PORT_VALUE = data;
	ENABLE_PULSE();
	#elif ACTIVE_MODE == FOUR_BIT_MODE
	LCD_PORT_VALUE = (data & 0xf0);
	ENABLE_PULSE();
	
	RESET_BIT(LCD_CTRL_PORT_VALUE,RW);
	SET_BIT(LCD_CTRL_PORT_VALUE,RS);
	LCD_PORT_VALUE = (data << 4);
	ENABLE_PULSE();
	#endif
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_Send_String(char* string)
{
	int counter = 0;
	while(*string > 0)
	{
		counter++;
		LCD_Send_Char(*string++);
		if(counter == 16)
			LCD_Cursor_XY(1,0);
		else if(counter == 33)
		{
			LCD_Clear_Screen();
			LCD_Cursor_XY(0,0);
			counter = 0;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_Cursor_XY(uint8 line, uint8 col)
{
	if(line == 0)
	{
		if(col < 16 && col >=0)
			LCD_Send_Command(LCD_BEGIN_AT_FIRST_ROW + col);
	}
	else if(line == 1)
	{
		if(col < 16 && col >=0)
			LCD_Send_Command(LCD_BEGIN_AT_SECOND_ROW + col);
	} 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LCD_display_number(int n)
{
	char int_to_string[10];
	sprintf(int_to_string,"%d",n);
	LCD_Send_String(int_to_string);
}