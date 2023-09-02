#ifndef _CA_H_
#define _CA_H_
#include "state.h"
//Define states
enum
{
CA_waiting_state,
CA_driving_state
}CA_STATE_ID;

//Declare states functions 
state_func(CA_waiting_func);
state_func(CA_driving_func);

// Declare pointer to function "IN US.c file" and extern here to make it in main file
void (*CA_state) (); 
#endif



