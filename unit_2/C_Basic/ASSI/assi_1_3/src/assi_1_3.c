/*
 ============================================================================
 Name        : assi_1_3.c
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
	int val1, val2;
		printf("Enter two numbers:");
		fflush(stdin); fflush(stdout);
		scanf("%d%d",&val1,&val2);
		printf("sum = %d",val1+val2);
}
