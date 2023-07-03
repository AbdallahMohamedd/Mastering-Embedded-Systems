#include "stdio.h"
#include "string.h"
void reverse(char data[], int length);
int main()
{
    char number[10000];
    printf("Enter the number: ");
    gets(number);
    reverse(number, strlen(number));
}

void reverse(char data[], int length)
{
    printf("the reverse number is: ");
    for (int i = length; i >= 0; i--)
    {
        printf("%c", data[i]);
    }
}