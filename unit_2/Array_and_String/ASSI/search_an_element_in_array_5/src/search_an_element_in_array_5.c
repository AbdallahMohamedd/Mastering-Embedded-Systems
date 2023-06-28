/*
 ============================================================================
 Name        : search_an_element_in_array_5.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main(void)
{
	int n,s;
	int data[50];
	printf("Enter no. of element: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&n);
	///////////////////////////////
	for(int i=0;i<n;i++)scanf("%d",&data[i]);
	///////////////////////////////
	printf("Enter the element to be searched: ");
	fflush(stdin);     fflush(stdout);
	scanf("%d",&s);
	///////////////////////////////
	int c=0;
	do
	{
		if(s==data[c])
		{
			printf("Number found at location %d",c+1);
			break;
		}
		c++;
	}while(c<n);
}
