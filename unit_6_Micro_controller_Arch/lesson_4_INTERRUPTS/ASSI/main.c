/*
 * main.c
 *
 * Created: 9/15/2023 4:36:27 AM
 *  Author: Abdullah Mohamed
 */ 

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define SET_BIT(address, bit) address |= (1<<bit)  
#define RESET_BIT(address, bit) address &= ~(1<<bit)
#define TOGGEL_BIT(address, bit) address ^= (1<<bit)
#define READ_BIT(address, bit) ((address & (1<<bit))>>bit)

#define IO_BASE 0x20 
#define INT_MCUCR *(volatile unsigned int *)(IO_BASE + 0x35)  //INT0 AND INT1
#define INT_MCUCSR *(volatile unsigned int *)(IO_BASE + 0x34) //INT2
#define INT_GICR *(volatile unsigned int *)(IO_BASE + 0x3B) 
#define IO_DDRD *(volatile unsigned int *)(IO_BASE + 0x11)
#define IO_PORTD *(volatile unsigned int *)(IO_BASE + 0x12)

int main(void)
{
	SET_BIT(IO_DDRD,5);
	SET_BIT(IO_DDRD,6);
	SET_BIT(IO_DDRD,7);
	
	//ENABLE INT
	SET_BIT(INT_GICR,5); //INT2
	SET_BIT(INT_GICR,6); //INT0
	SET_BIT(INT_GICR,7); //INT1
	
	//INT_MCUCR INT0 AND INT1 INT0 AT ANY LOGIC INT1 IN RISING
	SET_BIT(INT_MCUCR,0);//ISC00 INT0
	RESET_BIT(INT_MCUCR,1);//ISC01 INT0
	SET_BIT(INT_MCUCR,2);//ISC10 INT1
	SET_BIT(INT_MCUCR,3);//ISC11 INT1
	
	//INT_MCUCSR INT2 MAKE INT2 IN FALLING
	RESET_BIT(INT_MCUCSR,6);//ISC2 INT2
	
	
    sei();
    while(1);
}


ISR(INT0_vect)
{
	SET_BIT(IO_PORTD,5);
	_delay_ms(100);
	RESET_BIT(IO_PORTD,5);
}

ISR(INT1_vect)
{
	SET_BIT(IO_PORTD,6);
	_delay_ms(100);
	RESET_BIT(IO_PORTD,6);
}

ISR(INT2_vect)
{
	SET_BIT(IO_PORTD,7);
	_delay_ms(100);
	RESET_BIT(IO_PORTD,7);
}