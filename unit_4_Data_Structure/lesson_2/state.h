#ifndef _STATE_H_
#define _STATE_H_
#define debug
#define yarab printf("@ Func: %s, File: %s, Line: %d \n", __func__, __FILE__, __LINE__);

#include "stdio.h"
#include "stdlib.h"
#define state_func(_FUNC_NAME) void _FUNC_NAME() //function decleration
#define state_name(_FUNC_NAME) _FUNC_NAME //same of the above but used when pass function name to pointer 


//state connections
void US_SET_distance (int distance);
void DC_SET_speed (int speed);

#endif