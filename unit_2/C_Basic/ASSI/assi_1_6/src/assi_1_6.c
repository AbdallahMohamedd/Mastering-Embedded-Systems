/*
 ============================================================================
 Name        : assi_1_6.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main(void)
{
	float a,b,temp;
	printf("Enter value of a: ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&a);
	/////////////////////////////////////
	printf("Enter value of b: ");
	fflush(stdin);  fflush(stdout);
	scanf("%f",&b);
	/////////////////////////////////////
	temp=a; //temp=a, b=b, a=a
	a=b;    //temp=a, b=b, a=b,
	b=temp; //temp=a, b=a, a=b,
	printf("After swapping, value of a = %f\n",a);
	printf("After swapping, value of b = %f\n",b);
}
