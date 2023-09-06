/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:alarm_led.c
*/

/*used libraries*/
#include "../inc/led_alarm.h"
#include "../inc/driver.h"

// State pointer to function
void (*alarm_p_to_func)();

/*declare variables to used in only this file*/
int led_alarm = 0;

/*Initialize state connection function*/
void Set_Alarm_connection_FUNC(int alarm_status)
{
    if (alarm_status) // alarm =1
        alarm_p_to_func = state_name(turn_alarm_on_FUNC);
    else // alarm =0
        alarm_p_to_func = state_name(turn_alarm_off_FUNC);
}

/*Initialize function*/
state_func(alarm_init_FUNC)
{
    // initialize
    alarm_p_to_func = state_name(turn_alarm_off_FUNC);
    // printf("INIT. ALARM ;) \n");// use this line when test code before apply code in proteous
}

state_func(turn_alarm_off_FUNC)
{
    // state name
    alarm_current_state = turn_alarm_off;
    // take action
    // printf("led off\n");// use this line when test code before apply code in proteous
    Set_Alarm_actuator(1);
}

state_func(turn_alarm_on_FUNC)
{
    // state name
    alarm_current_state = turn_alarm_on;
    // take action
    Set_Alarm_actuator(0);
    // printf("led on\n");// use this line when test code before apply code in proteous
    Delay(60);
    // printf("delaaaaaaaaay\n");// use this line when test code before apply code in proteous
}
