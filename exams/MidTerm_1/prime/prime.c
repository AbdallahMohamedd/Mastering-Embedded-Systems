#include "stdio.h"
int prime(int n);
int main()
{
    unsigned int start, end;
    printf("Enter two numbers(intervals):\n");
    scanf("%d %d", &start, &end);
    //////////////////////////////////////////
    printf("The prime number between %d and %d are ", start, end);
    for (int i = start; i <= end; i++)
    {
        if (!prime(i))
            continue;
        else
            printf("%d ", prime(i));
    }
}

int prime(int n)
{
    for (int c = 2; c < n; c++)
        if ((n % c) == 0)
            return 0;
    return n;
}