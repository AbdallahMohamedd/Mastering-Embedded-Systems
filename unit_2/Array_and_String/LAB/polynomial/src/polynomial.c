/*
 * polynomial.c
 *
 *  Created on: Jun 25, 2023
 *      Author: Abdullah Mohamed
 */

#include "stdio.h"
int main()
{
	float x[5]={5,16,22,3.5,15};
	float y;
	for(int i=0;i<5;i++)
	{
		y=5*x[i]*x[i]+3*x[i]+2;
		printf("y(%f) = %f \n",x[i],y);
	}
}
