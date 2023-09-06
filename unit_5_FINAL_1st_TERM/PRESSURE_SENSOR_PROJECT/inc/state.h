/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:state.h
*/
/*Header protection*/
#ifndef _STATE_H_
#define _STATE_H_
#include "stdint.h"
/*Debug*/
//#define debug //////////// off 
//#define yarab printf("@ Func: %s, File: %s, Line: %d \n", __func__, __FILE__, __LINE__);


/*Macros to Function and Sympol Functions*/
#define state_func(_FUNC_NAME) void _FUNC_NAME() // function decleration
#define state_name(_FUNC_NAME) _FUNC_NAME        // same of the above but used when pass function name to pointer "Sympol Function"

/*Set connection*/
// implement in destination
void set_pressure_connection_FUNC(int pressure_val);
void Set_Alarm_connection_FUNC(int alarm_status);

#endif