#include "stdio.h"

int main()
{
    float n1, n2, n3;
    int flag1 = 0,flag2 = 0 , flag3 = 0;
    printf("Enter 3 numbers: ");
    scanf("%f%f%f", &n1, &n2, &n3);
    (n1>n2)?(flag1 = 1):(flag2 = 1);
    if(flag1)
    {
        if(n1>n3)
        printf("The biggest number is %f", n1);
        else
        printf("The biggest number is %f", n3);
    }
    else if(flag2)
    {
        if(n2>n3)
        printf("The biggest number is %f", n2);
        else
        printf("The biggest number is %f", n3);
        
    }
}