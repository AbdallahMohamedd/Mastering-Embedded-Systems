// variables declare only this file
#include "CA.h"
static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;

// State pointer to function
void (*CA_state)(); 

void US_SET_distance (int distance)
{
	CA_distance = distance ;
 	(CA_distance <= CA_threshold) ? (CA_state = state_name(CA_waiting_func)) : (CA_state = state_name(CA_driving_func));
 	printf("US------------distance = %d------------>CA\n",CA_distance);
}



state_func(CA_waiting_func)
{
	yarab;
	// state name
	CA_STATE_ID = CA_waiting_state;
	printf("CA_waiting STATE: CA_distance = %d  CA_speed = %d \n", CA_distance, CA_speed);
	// state action
	CA_speed = 0;
	DC_SET_speed (CA_speed);
}



state_func(CA_driving_func)
{
	// state name
	CA_STATE_ID = CA_driving_state;
	printf("CA_driving STATE: CA_distance = %d  CA_speed = %d \n", CA_distance, CA_speed);
	// state action
	CA_speed = 30;
	DC_SET_speed (CA_speed);
}
