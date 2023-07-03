#include "stdio.h"
void convert_to_binary(int d_number);
int main()
{
    int number, bit;
    printf("Enter the number:");
    scanf("%d", &number);
    convert_to_binary(number);
}
////////////////////////////////////////////////////////////////////////
void convert_to_binary(int d_number)
{
    int r[31], z = 0;
    printf("%d in binary is: ", d_number);
    for (int counter = 31, i = 0; counter >= 0; counter--, i++)
    {
        r[i] = 1 & (d_number >> counter);
        printf("%d", r[i]);
        if (r[i] == 1)
            z += 1;
    }
    printf("\nnumber of ones is: %d", z);
}
