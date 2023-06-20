/*
 ============================================================================
 Name        : largest.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main()
{
	float val1,val2,val3;
	printf("Enter Three values:");
	fflush(stdout);
	scanf("%f%f%f",&val1,&val2,&val3);
	if(val1>val2)
	{
		if (val1>val3)
		{
			printf("the biggest number is %f",val1);
		}
		else if (val3>val1)
		{
			printf("the biggest number is %f",val3);
		}
	}
	else if(val2>val1)
	{
		if (val2>val3)
		{
			printf("the biggest number is %f",val2);
		}
		else if (val3>val2)
		{
			printf("the biggest number is %f",val3);
		}
	}
	else if(val3>val2)
	{
		if (val1>val3)
		{
			printf("the biggest number is %f",val1);
		}
		else if (val3>val1)
		{
			printf("the biggest number is %f",val3);
		}
	}
}
