/*
 * calculator.c
 *
 * Created: 9/30/2023 8:36:53 AM
 * Author : Abdullah Mohamed
 */

#include <avr/io.h>
#include "LCD_DRIVER/lcd.h"
#include "KPAD_DRIVER/kpad.h"

static int temp_0 = 0, temp_1 = 0, temp_2 = 0, temp_3 = 0, temp_4 = 0;
void modify_number(int number_counter, char press_key);
int main(void)
{
	int flag_1 = 1, flag_2 = 1, sum = 0, sub = 0, multi = 0, div = 0, mod = 0, root = 0, res = 0;
	int first_number, second_number;
	char press_key;
	int number_counter = 0;
	LCD_INIT_FUNC();
	KPAD_INIT_FUNC();
	while (1)
	{
		while (flag_1)
		{
			press_key = KPAD_GET_CHAR();
			switch (press_key)
			{
			case '0':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '1':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '2':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '3':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '4':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '5':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '6':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '7':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '8':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '9':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '+':
				LCD_SEND_CHAR_FUNC(press_key);
				sum = 1;
				flag_1 = 0;
				break;
			/////////////////////////////////////////////
			case '-':
				LCD_SEND_CHAR_FUNC(press_key);
				sub = 1;
				flag_1 = 0;
				break;
			/////////////////////////////////////////////
			case '*':
				LCD_SEND_CHAR_FUNC(press_key);
				multi = 1;
				flag_1 = 0;
				break;
			/////////////////////////////////////////////
			case '/':
				LCD_SEND_CHAR_FUNC(press_key);
				div = 1;
				flag_1 = 0;
				break;
			/////////////////////////////////////////////
			case 'R':
				LCD_SEND_CHAR_FUNC(press_key);
				root = 1;
				flag_1 = 0;
				break;
			/////////////////////////////////////////////
			case '%':
				LCD_SEND_CHAR_FUNC(press_key);
				mod = 1;
				flag_1 = 0;
				break;
				/////////////////////////////////////////////
			}
		}
		first_number = temp_0 + temp_1 + temp_2 + temp_3 + temp_4;
		temp_0 = 0, temp_1 = 0, temp_2 = 0, temp_3 = 0, temp_4 = 0;
		number_counter = 0;
		while (flag_2)
		{
			press_key = KPAD_GET_CHAR();
			switch (press_key)
			{
			case '0':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '1':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '2':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '3':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '4':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '5':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '6':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '7':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '8':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			/////////////////////////////////////////////
			case '9':
				LCD_SEND_CHAR_FUNC(press_key);
				modify_number(number_counter, press_key);
				number_counter++;
				break;
			case '=':
				LCD_SEND_CHAR_FUNC(press_key);
				flag_2 = 0;
				LCD_SET_CURSOR_FUNC(1, 0);
				break;
			}
		}
		second_number = temp_0 + temp_1 + temp_2 + temp_3 + temp_4;
		if (sum)
		{
			res = second_number + first_number;
			LCD_DISPLAY_NUMBER_FUNC(res);
		}
		else if (sub)
		{
			res = first_number - second_number;
			LCD_DISPLAY_NUMBER_FUNC(res);
		}
		else if (multi)
		{
			res = second_number * first_number;
			LCD_DISPLAY_NUMBER_FUNC(res);
		}
		else if (mod)
		{
			res = first_number % second_number;
			LCD_DISPLAY_NUMBER_FUNC(res);
		}
		else if (div)
		{
			res = first_number / second_number;
			LCD_DISPLAY_NUMBER_FUNC(res);
		}
		while (KPAD_GET_CHAR() != '!')
			;
		LCD_CLEAR_SCREEN_FUNC();
		LCD_SET_CURSOR_FUNC(0, 0);
		flag_2 = 1;
		flag_1 = 1;
		temp_0 = 0, temp_1 = 0, temp_2 = 0, temp_3 = 0, temp_4 = 0;
		first_number = 0;
		second_number = 0;
	}
}

void modify_number(int number_counter, char press_key)
{
	switch (number_counter)
	{
	case 0:
		temp_0 = (press_key - 48) * 1;
		break;
	case 1:
		temp_0 *= 10;
		temp_1 = (press_key - 48) * 1;
		break;
	case 2:
		temp_0 *= 10;
		temp_1 *= 10;
		temp_2 = (press_key - 48) * 1;
		break;
	case 3:
		temp_0 *= 10;
		temp_1 *= 10;
		temp_2 *= 10;
		temp_3 = (press_key - 48) * 1;
		break;
	case 4:
		temp_0 *= 10;
		temp_1 *= 10;
		temp_2 *= 10;
		temp_3 *= 10;
		temp_4 = (press_key - 48) * 1;
		break;
	}
}