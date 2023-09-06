#include "DC.h"
#include"stdio.h"
#include "stdlib.h"
static int DC_speed = 0;

void (*DC_P_FUNC)();

void DC_INIT()
{
	// initialize dc motor
	printf("INIT DC Motor\n");
}

void DC_SET_speed(int speed)
{
	DC_speed = speed;
	DC_P_FUNC = state_name(DC_func_BUSY);
	printf("CA------------speed = %d------------>DC\n", DC_speed);
}

state_func(DC_func_IDEAL)
{
	// state name
	DC_STATE = DC_state_IDEAL;
	// event check
	printf("DC_ideal_state:\tspeed: %d \n", DC_speed);
}
state_func(DC_func_BUSY)
{
	// state name
	DC_STATE = DC_state_BUSY;
	// state action
	//DC_speed = 30;
	DC_P_FUNC = state_name(DC_func_IDEAL);
	// event check
	printf("DC_busy_state:\tspeed: %d \n", DC_speed);
}
