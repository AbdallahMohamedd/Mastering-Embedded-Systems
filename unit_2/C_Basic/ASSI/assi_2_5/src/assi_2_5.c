/*
 ============================================================================
 Name        : assi_2_5.c
 Author      : Abdullah Mohamed
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main(){
    char test;
    printf("Enter a character: ");
    fflush(stdin);      fflush(stdout);
    scanf("%c",&test);
    if ((test>=97 && test<=122) || (test>=65 && test<=90)) printf("%c is an alphabet",test);
    else printf("%c is not an alphabet",test);
}
