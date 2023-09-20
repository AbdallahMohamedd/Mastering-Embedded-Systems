/*
 * main.c
 *
 * Created: 9/20/2023 10:49:34 PM
 *  Author: Abdullah Mohamed
 */ 

#include <xc.h>
#define SET_BIT(ADDRESS, BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS, BIT) ADDRESS &= ~(1<<BIT)

#define F_CPU 8000000UL

void INIT_GPIO(void);
void LED_1(void);
void LED_2(void);
void LED_3(void);
void BUZZER(void);
void MY_DELAY(int t);


int main(void)
{
	INIT_GPIO();
    while(1)
    {
        LED_1();
		LED_2();
		LED_3();		 
		BUZZER();
    }
}


void INIT_GPIO(void)
{
	SET_BIT(DDRD,4);//buzzer
	SET_BIT(DDRD,5);//led 1
    SET_BIT(DDRD,6);//led 2
	SET_BIT(DDRD,7);//led 3
}

void LED_1(void)
{
	SET_BIT(PORTD,5);
	MY_DELAY(10000);
	RESET_BIT(PORTD,5);
	MY_DELAY(2000);
}

void LED_2(void)
{
	SET_BIT(PORTD,6);
	MY_DELAY(10000);
	RESET_BIT(PORTD,6);
    MY_DELAY(2000);
}

void LED_3(void)
{
	SET_BIT(PORTD,7);
	MY_DELAY(10000);
	RESET_BIT(PORTD,7);
    MY_DELAY(2000);
}

void BUZZER(void)
{
	SET_BIT(PORTD,4);
	MY_DELAY(10000);
	RESET_BIT(PORTD,4);
	MY_DELAY(2000);
}

void MY_DELAY(int t)
{
	for(int i=0; i<t; i++);
}
