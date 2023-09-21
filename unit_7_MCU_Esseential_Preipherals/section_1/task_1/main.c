/*
 * task_1.c
 *
 * Created: 9/21/2023 4:15:18 AM
 * Author : Abdullah Mohamed
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "util/delay.h"

int main(void)
{
	volatile int i = 0 ;
	PORTA =0b11111111;
    while (1) 
    {
		DDRA |= (1<<i);
		_delay_ms(500);
		i++;
		if(i==8)
		{
			i = 7;
			for(;;i--)
			{
			DDRA &= ~(1<<i);
			_delay_ms(500);	
			if(i<0)
			{
				i=0;
				break;
			}
			}
		}
    }
}

