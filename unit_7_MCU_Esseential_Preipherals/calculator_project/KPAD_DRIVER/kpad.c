/*
 * kpad.c
 *
 * Created: 9/30/2023 9:46:41 AM
 *  Author: Abdullah Mohamed
 */ 


/*
 * kpad.c
 *
 * Created: 9/30/2023 6:07:39 AM
 *  Author: Abdullah Mohamed
 */ 


#include "kpad.h"

void KPAD_INIT_FUNC()
{
	KPAD_ROW_PORT_DIRECTION = 0X00;
	KPAD_COL_PORT_DIRECTION = 0X3F;
	
	KPAD_COL_PORT_VALUE = 0x3F;
	KPAD_ROW_PORT_VALUE = 0x0F;
}


char KPAD_GET_CHAR()
{
	for(int i = 0; i<6; i++)//col
	{
		SET_BIT(KPAD_COL_PORT_VALUE,C0);
		SET_BIT(KPAD_COL_PORT_VALUE,C1);
        SET_BIT(KPAD_COL_PORT_VALUE,C2);
		SET_BIT(KPAD_COL_PORT_VALUE,C3);
		SET_BIT(KPAD_COL_PORT_VALUE,C4);
		SET_BIT(KPAD_COL_PORT_VALUE,C5);		

		RESET_BIT(KPAD_COL_PORT_VALUE,i);
		for(int j = 0; j<4; j++)
		{
			 if(!READ_BIT(KPAD_ROW_PORT_PIN, j))
			 {
				 while(!READ_BIT(KPAD_ROW_PORT_PIN, j));
				 switch(i)
				 {
					 //====================================
					 case 0:
					 if(j==0)
					 return '!';
					 else if(j==1)
					 return 'N';
					 else if(j==2)
					 return '%';
					 else if(j==3)
					 return 'R';
					 break;
					 //======================================
					 case 1:
					 if(j==0)
					 return '7';
					 else if(j==1)
					 return '4';
					 else if(j==2)
					 return '1';
					 else if(j==3)
					 return '0';
					 break;
					 //========================================
					 case 2:
					 if(j==0)
					 return '8';
					 else if(j==1)
					 return '5';
					 else if(j==2)
					 return '2';
					 else if(j==3)
					 return '.';
					 break;
					 //=======================================
					 case 3:
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
					 case 4:
					 if(j==0)
					 return '*';
					 else if(j==1)
					 return '-';
					 else if(j==2)
					 return '+';
					 else if(j==3)
					 return '+';
					 break;
					 //=======================================
					 case 5:
					 if(j==0)
					 return '/';
					 else if(j==1)
					 return 'N';
					 else if(j==2)
					 return 'M';
					 else if(j==3)
					 return 'M';
					 break;
				 }
			 }
		 }
	 }
	 return 'N';
}