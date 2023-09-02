#ifndef _US_H_
#define _US_H_
#include "state.h"

// define state
enum
{
    US_state_BUSY
} US_STATE;

// Declare US Motor Function
void US_INIT();
state_func(US_func_BUSY);

// Declare pointer to function "IN US.c file" and extern here to make it in main file
extern void (*US_P_FUNC)();

#endif