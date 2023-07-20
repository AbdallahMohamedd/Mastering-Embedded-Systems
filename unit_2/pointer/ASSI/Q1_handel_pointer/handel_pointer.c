#include "stdio.h"
int main()
{
    int m = 29;
    int *ab = &m;
    printf("Address of m : %x\n", &m);
    printf("Value   of m : %d\n", m);
    printf("****************************************************************\n");
    printf("Now ab is assigned with the address of m\n");
    printf("Address of pointer ab : %x\n", ab);
    printf("content of pointer ab : %d\n", *ab);
    printf("****************************************************************\n");
    printf("The value of m assigned to 34 now\n");
    m = 34;
    printf("Address of pointer ab : %x\n", ab);
    printf("content of pointer ab : %d\n", *ab);
    printf("****************************************************************\n");
    printf("The pointer variable ab is assigned with the value 7 now\n");
    *ab = 7;
    printf("Address of m : %x\n", &m);
    printf("value   of m : %d\n", m);
}