/*
 ============================================================================
 Name        : lab3.c
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
	printf("Please, Enter two number:\n");
	fflush(stdout);
	scanf("%d%d",&a,&b);
	(a>b)?printf("the smallest is %d",b):printf("the smallest is %d",a);
}
