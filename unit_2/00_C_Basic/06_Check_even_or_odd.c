#include "stdio.h"
int main()
{
    int n;
    printf("Enter the number \n");
    scanf("%d", &n);
    if (!(n % 2))
    {
        printf("Even number");
    }
    else
    {
        printf("odd number");
    }
}