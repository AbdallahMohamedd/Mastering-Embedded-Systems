/*
 ============================================================================
 Name        : assi_1_7.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main()
{
	int a,b;
	printf("Enter value of a: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&a);
	/////////////////////////////////////
	printf("Enter value of b: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&b);
	/////////////////////////////////////
	b=b+a;
	a=b-a;
	b=b-a;
	printf("After swapping, value of a = %d\n",a);
	printf("After swapping, value of b = %d\n",b);
}
