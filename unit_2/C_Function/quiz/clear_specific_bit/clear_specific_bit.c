#include "stdio.h"
int ccc(int a, int b);
int main()
{
    int number, bit;
    printf("Enter the number:");
    scanf("%d", &number);
    printf("Enter order of bit:");
    scanf("%d", &bit);
    printf("Output: %d", ccc(number, bit));
}

int ccc(int a, int b)
{
    return (a &= ~(1 << b));
}