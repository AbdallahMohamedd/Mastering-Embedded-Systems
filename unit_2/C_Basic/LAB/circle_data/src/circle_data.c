/*
 ============================================================================
 Name        : lab1.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main ()
{
	float radius;
	char choice;
	printf("Enter circle radius:");
	fflush(stdin); 	fflush(stdout);
	scanf("%f",&radius);
	printf("Enter your choice (a to print the area, c to print the circumference ");
	fflush(stdin); 	fflush(stdout);
	scanf("%c",&choice);
	if (choice=='a')
	{
		printf("area is %f",3.1415*radius*radius);
	}
	else if (choice=='c')
	{
		printf("circumference is %f",3.1415*radius*2);
	}
	else
	{
		printf("wrong choice");
	}


}
