/*
 ============================================================================
 Name        : assi_2_4.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main ()
{
	float number;
	printf("Enter a number :");
	fflush(stdin);   fflush(stdout);
	scanf("%f",&number);
	////////////////////////////////////////////
	if(number==0)printf("U entered zerooo");
	else(number>0)?printf("%f is +ve",number):printf("%f is -ve",number);
}
