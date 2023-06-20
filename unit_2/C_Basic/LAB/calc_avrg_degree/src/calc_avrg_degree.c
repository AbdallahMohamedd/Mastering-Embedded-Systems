/*
 ============================================================================
 Name        : lab5.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdio.h"
int main ()
{
	int n,i;
	float degree,sum;
	printf("Please, Enter the number of student: ");
	fflush(stdout);
	scanf("%d",&n);
	////////////////////////////////////////////////////
	for(i=1,sum=0;i<=n;i++)
	{
		printf("Please, Enter student(%d)degree: ",i);
	    fflush(stdout);
		scanf("%f",&degree);
		sum+=degree;
	}
	printf("the avrg is %f ",sum/n);
}
