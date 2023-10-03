/*
 * LCD_Driver.c
 *
 * Created: 9/28/2023 5:48:07 AM
 * Author : Abdullah Mohamed
 */ 

#include <avr/io.h>
#include "LCD/lcd.h"
#include "KPAD/kpad.h"

int main(void)
{
	LCD_Init();
	int counter = 0;
	//LCD_Send_String("Abdullah Mohamed Nada shabaan");
	//LCD_display_number(12891);
	KPAD_INIT();
	while(1)
	{
		char pressed_key = KPAD_GET_CHAR();
		switch(pressed_key)
		{
			case '!':
			LCD_Clear_Screen();
			break;
			case 'N':
			break;
			default:
			{
				LCD_Send_Char(pressed_key);
				counter++;
				if(counter == 16)
					LCD_Cursor_XY(1,0);
				if(counter == 33)
				{
					LCD_Clear_Screen();
					LCD_Cursor_XY(0,0);
					counter = 0;
				}
			}
		}
	}
}
