/*
 ============================================================================
 Name        : assi_2_6.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int number;
	printf("Enter an intger number: ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&number);
	int sum =0;
	for (int i=0; i<=number; i++)
	{
		sum+=i;
	}
	printf("sum = %d",sum);
}
