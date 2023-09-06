/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:brain.c
*/

/*used libraries*/
#include "../inc/brain.h"

// State pointer to function 
void (*brain_p_to_func)();

/*declare variables to used in only this file*/
int brain_pressure_val = 0;
int brain_threshold = 20;
int brain_alarm_status = 0;

/*Initialize state connection function*/
void set_pressure_connection_FUNC(int pressure_val)
{
    brain_pressure_val = pressure_val;
    (brain_pressure_val > brain_threshold) ? (brain_p_to_func = state_name(onnn_FUNC)) : (brain_p_to_func = state_name(sleeping_FUNC));
    // printf("now i'm in brain and take right action \n");// use this line when test code before apply code in proteous
}

state_func(sleeping_FUNC)
{
    // state name
    brain_current_state = sleeping;
    // take action
    // printf("sleeeeeeeeeeeep\n");// use this line when test code before apply code in proteous
    // send alarm value to alarm to take right action by using state connection function
    Set_Alarm_connection_FUNC(0);
}

state_func(onnn_FUNC)
{
    // state name
    brain_current_state = onnn;
    // take action
    // printf("turn alarm onnnnnn\n");// use this line when test code before apply code in proteous
    // send pressure sensor value to brain to take right action by using state connection function
    Set_Alarm_connection_FUNC(1);
}
