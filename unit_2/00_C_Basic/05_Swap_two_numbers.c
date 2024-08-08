#include "stdio.h"
int main()
{
    int n1, n2, temp;
    printf("Enter two number to swapping: ");
    scanf("%d%d", &n1, &n2);
    temp = n1;
    n1 = n2;
    n2 = temp;
    printf("After Swapping %d & %d ",n1,n2);
}