#ifndef _DC_H_
#define _DC_H_
#include "state.h"

// define state
enum
{
    DC_state_IDEAL,
    DC_state_BUSY
} DC_STATE;

// Declare DC Motor Function
void DC_INIT();
state_func(DC_func_IDEAL);
state_func(DC_func_BUSY);

// Declare pointer to function "IN dc.c file" and extern here to make it in main file
extern void (*DC_P_FUNC)();

#endif