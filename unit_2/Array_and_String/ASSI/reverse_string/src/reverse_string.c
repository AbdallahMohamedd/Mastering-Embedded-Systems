/*
 ============================================================================
 Name        : reverse_string.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char string[100];
	int L=0;
	printf("Enter a string: ");
	fflush(stdin);   fflush(stdout);
	gets(string);
	printf("Reverse string is ");
	for(L=strlen(string);L>=0;L--)
	{
		printf("%c",string[L]);
	}

}
