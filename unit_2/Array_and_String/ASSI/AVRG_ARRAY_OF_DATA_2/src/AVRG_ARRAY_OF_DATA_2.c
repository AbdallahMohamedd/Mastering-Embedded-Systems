/*
 ============================================================================
 Name        : AVRG_OF_ARRAY_DATA_2.c
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
	int number_of_data;
	float sum=0;
	float data[50];
	printf("Enter the number of data: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&number_of_data);
	for(int i=0; i<number_of_data; i++)
	{
		printf("Enter number: ");
		fflush(stdin);    fflush(stdout);
		scanf("%f",&data[i]);
	}
	for(int i=0; i<number_of_data; i++)
	{
		sum+=data[i];
	}
	float avrg = sum/number_of_data;
	printf("Average = %f",avrg);
}
