/*
 ============================================================================
 Name        : assi_2_2.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	char alpha;
	printf("Enter an alphabet : ");
	fflush(stdin);      fflush(stdout);
	scanf("%c",&alpha);
	/////////////////////////////////
	if ((alpha=='a')||(alpha=='e')||(alpha=='o')||(alpha=='i')||(alpha=='u')||
		(alpha=='A')||(alpha=='E')||(alpha=='U')||(alpha=='O')||(alpha=='I'))
	{
		printf("%c is vowel.",alpha);
	}
	else {
		printf("%c is consonant.",alpha);
	}
}
