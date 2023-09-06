/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:main.c
*/

/*used libraries*/
#include "../inc/led_alarm.h"
#include "../inc/pressure_sensor.h"
#include "../inc/brain.h"
#include "../inc/driver.h"
#include "stdio.h"
#include "stdlib.h"

void setup() 
{
    // init Block
    alarm_init_FUNC();
    // yarab;   Debug
    pressure_init_FUNC();
    // yarab;   Debug
    //  set state pointer 
    brain_p_to_func = state_name(sleeping_FUNC);
}

int main()
{
    GPIO_INITIALIZATION();
    volatile int d;
    setup();
    while (1)
    {
        // yarab;   Debug
        //  call state for each block
        brain_p_to_func();
        // yarab;   Debug
        alarm_p_to_func();
        // yarab;   Debug
        PS_p_to_func();
        // yarab;   Debug
        for (d = 0; d <= 100000; d++) ;
    }
}