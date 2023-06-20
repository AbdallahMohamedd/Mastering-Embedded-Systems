/*
 ============================================================================
 Name        : assi_1_4.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float val1, val2;
		printf("Enter two numbers:");
		fflush(stdin); fflush(stdout);
		scanf("%f%f",&val1,&val2);
		printf("Product = %f",val1*val2);
}
