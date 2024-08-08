#include "stdio.h"
int main()
{
    float n;
    printf("Enter the number: ");
    scanf("%f", &n);
    if (n > 0) // +ve number
    {
        printf("%f is a +ve number", n);
    }
    else if (n < 0)
    {
        printf("%f is a -ve number", n);
    }
    else
        printf("0 is a Zero");
}