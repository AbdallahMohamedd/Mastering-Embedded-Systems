/*
 ============================================================================
 Name        : assi_2_1.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int number;
	printf("Enter an intger numberyou want to check: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&number);
	///////////////////////////////////////////////
	(number%2)?printf(" %d is odd",number):printf(" %d is even",number);
}
