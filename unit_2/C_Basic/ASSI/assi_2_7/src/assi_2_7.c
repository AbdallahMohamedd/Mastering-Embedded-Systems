/*
 ============================================================================
 Name        : assi_2_7.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,r=1;
	printf("Enter an intger number: ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&n);
	////////////////////////////////
	if(n<0)
	{
		printf("Error!! Factorial of -ve number doesn't exist");
		return 0;
	}
	else
	{
		for(int i=n;i>1;i--)
		{
			r*=i;
		}
		printf("Factorial %d is %d",n,r);
	}
}
