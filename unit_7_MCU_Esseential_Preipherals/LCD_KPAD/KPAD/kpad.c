/*
 * kpad.c
 *
 * Created: 9/30/2023 6:07:39 AM
 *  Author: Abdullah Mohamed
 */ 


#include "kpad.h"

int KPAD_R[] = {R0, R1, R2, R3}; 
int KPAD_C[] = {C0, C1, C2, C3};
void KPAD_INIT()
{
	KPAD_PORT_DIRECTION = 0XF0;
	KPAD_PORT_VALUE = 0xFF;
}


char KPAD_GET_CHAR()
{
	for(int i = 0; i<4; i++)//col
	{
		SET_BIT(KPAD_PORT_VALUE,C0);
		SET_BIT(KPAD_PORT_VALUE,C1);
        SET_BIT(KPAD_PORT_VALUE,C2);
		SET_BIT(KPAD_PORT_VALUE,C3);
		RESET_BIT(KPAD_PORT_VALUE,KPAD_C[i]);
		for(int j = 0; j<4; j++)
		{
			 if(!READ_BIT(KPAD_PORT_PIN, j))
			 {
				 while(!READ_BIT(KPAD_PORT_PIN, j));
				 switch(i)
				 {
					 //====================================
					 case 0:
					 if(j==0)
					 return '7';
					 else if(j==1)
					 return '4';
					 else if(j==2)
					 return '1';
					 else if(j==3)
					 return '!';
					 break;
					 //======================================
					 case 1:
					 if(j==0)
					 return '8';
					 else if(j==1)
					 return '5';
					 else if(j==2)
					 return '2';
					 else if(j==3)
					 return '0';
					 break;
					 //========================================
					 case 2:
					 if(j==0)
					 return '9';
					 else if(j==1)
					 return '6';
					 else if(j==2)
					 return '3';
					 else if(j==3)
					 return '=';
					 break;
					 //=======================================
					 case 3:
					 if(j==0)
					 return '/';
					 else if(j==1)
					 return '*';
					 else if(j==2)
					 return '-';
					 else if(j==3)
					 return '+';
					 break;
				 }
			 }
		 }
	 }
	 return 'N';
}