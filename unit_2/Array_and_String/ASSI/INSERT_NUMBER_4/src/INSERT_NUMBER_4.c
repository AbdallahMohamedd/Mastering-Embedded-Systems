/*
 ============================================================================
 Name        : INSERT_ELEMENT_IN_ARRAY.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	int data[50];
	int no;
	printf("Enter no. of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&no);
	for(int i=0; i<no; i++)
	{
		scanf("%d",&data[i]);
	}

	int inserted;
	printf("\nEnter the element to be inserted: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&inserted);
	int location;
	printf("Enter the location: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d",&location);
	for(int i=0; i<no; i++)
	{
		(i==location-1)?printf("%d %d ",inserted,data[i]):printf("%d ",data[i]);
	}
}
