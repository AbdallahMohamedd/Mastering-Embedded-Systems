/*
Master Embedded Systems "learn in depth"
Eng.: Keroles Khalil
Unit 5********PROJECT_1********Topic:pressure detector project
File:driver.c
*/

/*used libraries*/
#include "../inc/driver.h"

void Delay(int nCount)
{
	for (; nCount != 0; nCount--);
}

int getPressureVal()
{
	return (GPIOA_IDR & 0xFF);
}

void Set_Alarm_actuator(int i)
{
	if (i == 1)
	{
		SET_BIT(GPIOA_ODR, 13);
	}
	else if (i == 0)
	{
		RESET_BIT(GPIOA_ODR, 13);
	}
}

void GPIO_INITIALIZATION()
{
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
