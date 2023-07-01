#include "stdio.h"
int factorial(int x);
int main()
{
    printf("factorial of (%d) = %d\n",6 , factorial(6));
}

int factorial(int x)
{
    if(x==1) return 1;
    return x*factorial((x-1)) ;
}