#include "stdio.h"
void reverse(int n);
int main()
{
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    printf("Reverse number:");
    reverse(n);
}

void reverse(int n)
{
    static int r = 0;
    if (n != 0)
    {
        r = n % 10;
        printf("%d", r);
        reverse(n / 10);
    }
}