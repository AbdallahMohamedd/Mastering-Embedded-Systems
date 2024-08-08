#include "Stdio.h"

int main()
{
    int n ;
    printf("enter the number to stop ");
    scanf("%d",&n);
    int sum = 0 ;
    for(int i =0; i<=n; i++)
    sum = sum + i;
    printf("Sum: %d",sum);
}