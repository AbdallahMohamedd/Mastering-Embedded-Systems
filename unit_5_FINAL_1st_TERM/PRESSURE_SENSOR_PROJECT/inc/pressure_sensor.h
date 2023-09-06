/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:pressure_sensor.h
*/

/*Header protection*/
#ifndef _SENSOR_H_
#define _SENSOR_H_

/*used libraries*/
#include "state.h"

/*Enumuration to make code more readable*/
enum
{
    pressure_init,
    turn_sensor_on
} preusser_current_state;

/*Declare pressure sensor Function*/
state_func(pressure_init_FUNC);
state_func(turn_sensor_on_FUNC);
 
/*Declar pointer in pressure_sensor.c file and make it extern to see in main.c file*/
extern void (*PS_p_to_func) ();

#endif