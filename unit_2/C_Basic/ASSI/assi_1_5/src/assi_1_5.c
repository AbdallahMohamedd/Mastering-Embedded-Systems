/*
 ============================================================================
 Name        : assi_1_5.c
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
	char random;
	printf("Enter a character:");
	fflush(stdin);   fflush(stdout);
	scanf("%c",&random);
	printf("ASCII value of %c = %d",random,random);
}
