/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:pressure_sensor.c
*/

/*used libraries*/
#include "../inc/pressure_sensor.h"
#include "../inc/driver.h"

// State pointer to function
void (*PS_p_to_func)();

/*declare variables to used in only this file*/
int PS_pressure_val = 0;

// use this function when test code before apply code in proteous
/*Random function*/
/*int PS_GET_RANDOM_FUNC(int l, int r, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        int rand_num = (rand() % (r - l + 1)) + l;
        return rand_num;
    }
}*/

/*Initialize function*/
state_func(pressure_init_FUNC)
{
    // initialize
    PS_p_to_func = state_name(turn_sensor_on_FUNC);
    // printf("INIT. PRESSURE SENSOR ;) \n");// use this line when test code before apply code in proteous
}

state_func(turn_sensor_on_FUNC)
{
    // state name
    preusser_current_state = turn_sensor_on;
    // take action,,, read current value of pressure sensor
    PS_pressure_val = getPressureVal();
    // PS_pressure_val = PS_GET_RANDOM_FUNC(15, 25, 1); // to test
    // printf("Reading %d bar now!! \n", PS_pressure_val); // to test
    // send pressure sensor value to brain to take right action by using state connection function
    // printf("send pressure value to brain now\n");// use this line when test code before apply code in proteous
    set_pressure_connection_FUNC(PS_pressure_val);
    PS_p_to_func = state_name(turn_sensor_on_FUNC); // set pointer again
}
