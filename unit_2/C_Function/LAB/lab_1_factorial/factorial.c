#include "stdio.h"
int factorial(int x);
int main()
{
    printf("factorial(%d) = %d",5 , factorial(5));
}

int factorial(int x)
{
    int r=1;
    while (x != 1)
    {
        r*=x;
        x--;
    }
    return r;
}