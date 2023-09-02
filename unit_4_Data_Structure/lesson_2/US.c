#include "US.h"
// variables declare only this file
static int US_distance = 0 ;

// State pointer to function
void (*US_P_FUNC) ();

int US_GET_DISTANCE_RANDOM(int l, int r, int count);

void US_INIT()
{
	//initialize US
	printf("INIT US ;) \n");
}

state_func(US_func_BUSY)
{
	//state name 
	US_STATE = US_state_BUSY;
	//state action
	US_distance = US_GET_DISTANCE_RANDOM(45,55,1);
	printf("US_Waiting state: distance = %d \n",US_distance);
    US_SET_distance (US_distance);
    US_P_FUNC = state_name(US_func_BUSY);
}




int US_GET_DISTANCE_RANDOM(int l, int r, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
}