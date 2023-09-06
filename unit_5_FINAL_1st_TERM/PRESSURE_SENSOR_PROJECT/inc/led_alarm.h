/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:led_alarm.h
*/

/*Header protection*/
#ifndef _LED_ALARM_H_
#define _LED_ALARM_H_

/*used libraries*/
#include "state.h"

/*Enumuration to make code more readable*/
enum
{
    alarm_init,
    turn_alarm_off,
    turn_alarm_on
} alarm_current_state;

/*Declare alarm Function*/
state_func(alarm_init_FUNC);
state_func(turn_alarm_off_FUNC);
state_func(turn_alarm_on_FUNC);

/*Declar pointer in alarm_sensor.c file and make it extern to see in main.c file*/
extern void (*alarm_p_to_func)();

#endif