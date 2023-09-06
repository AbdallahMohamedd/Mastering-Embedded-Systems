/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:brain.h
*/

/*Header protection*/
#ifndef _BRAIN_H_
#define _BRAIN_H_

/*used libraries*/
#include "state.h"

/*Enumuration to make code more readable*/
enum
{
    sleeping,
    onnn
} brain_current_state;

/*Declare pressure sensor Function*/
state_func(sleeping_FUNC);
state_func(onnn_FUNC);

/*Declar pointer in brain.c file and make it extern to see in main.c file*/
extern void (*brain_p_to_func)();

#endif