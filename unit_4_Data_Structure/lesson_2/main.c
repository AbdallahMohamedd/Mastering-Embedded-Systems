#include "CA.h"
#include "US.h"
#include "DC.h"
#include "CA.c"
#include "US.c"
#include "DC.c"

void setup()
{
	//yarab;
	// init all the drivers
	// init IRQ..........
	// init HAL ultra_sonick driver, DC_Motor driver
	// init Block
	DC_INIT();
	//yarab;
	US_INIT();
	//yarab;
	// set state pointers for each block
	CA_state = state_name(CA_waiting_func);
	//yarab;
	US_P_FUNC = state_name(US_func_BUSY);
}

int main()
{
	volatile int d;
	setup();
	while (1)
	{
		//yarab;
		// call state for each block
		CA_state();
		//yarab;
		DC_P_FUNC();
		//yarab;
		US_P_FUNC();
		//yarab;
		for (d; d <= 1000; d++)
			;
	}
}