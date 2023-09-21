/*
 * task_1.c
 *
 * Created: 9/21/2023 4:15:18 AM
 * Author : Abdullah Mohamed
 */
#define F_CPU 8000000UL
#include <avr/io.h>
#include "util/delay.h"

#define SET_BIT(address, bit) address |= (1 << bit)
#define RESET_BIT(address, bit) address &= ~(1 << bit)
#define TOGGEL_BIT(address, bit) address ^= (1 << bit)
#define READ_BIT(address, bit) ((address & (1 << bit)) >> bit)

int main(void)
{
	volatile int i = 0;
	DDRA = 0b11111111;
	DDRC = 0b00000000;
	PORTC = 0b00000001;
	while (1)
	{
		if (!READ_BIT(PINC, 0)) // press
		{
			SET_BIT(PORTA, i);
			i++;
			_delay_ms(500);
			if (i == 8)
			{
				i = 7;
				while (i >= 0)
				{
					if (!READ_BIT(PINC, 0))
					{
						RESET_BIT(PORTA, i);
						i--;
						_delay_ms(500);
					}
				}
			}
		}
	}
}