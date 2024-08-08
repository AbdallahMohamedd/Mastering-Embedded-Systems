#include "stdio.h"

int main()
{
    char c;
    printf("Please, Enter the character ");
    scanf("%c",&c);
    if(c>=97 && c<=122)
    printf("you entered alphabet");
    else if (c>=65 && c<=90)
    printf("you entered alphabet");
    else
    printf("you NOT entered alphabet");
    }