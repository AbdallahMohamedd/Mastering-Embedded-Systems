#include "stdio.h"
int main()
{
    int n;
    int flag;
    printf("Enter the number: ");
    scanf("%d", &n);
    (n > 0) ? (flag = 1) : (flag = 0);
    if (flag)
    {
        for (int i = n-1; i > 0 ; i--)
        {
            n = n * i;
        }
        printf("Factorial = %d", n);
    }
    else
    {
        printf("Error");
    }
}