/*
 ============================================================================
 Name        : find_the_length_of_string_7.c
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
	char string[100];
	printf("Enter a string: ");
	fflush(stdin);   fflush(stdout);
	gets(string);
	//////////////////////////////////
	int i=0;
	while(string[i]!=0)
	{
		i++;
	}
	printf("Length of string: %d",i);
}
