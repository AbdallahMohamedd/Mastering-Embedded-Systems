#include "stdio.h"
int check_specific_bit(int d_number, int order_of_bit);
void convert_to_binary(int d_number);
int main()
{
    int number, bit;
    printf("Enter the number:");
    scanf("%d", &number);
    printf("Enter order of bit:");
    scanf("%d", &bit);
    convert_to_binary(number);
    check_specific_bit(number,bit);
}
////////////////////////////////////////////////////////////////////////
void convert_to_binary(int d_number)
{
    printf("%d in binary is: ", d_number);
    for (int counter = 31; counter >= 0; counter--)
    {
        printf("%d", (1 & (d_number >> counter)));
    }
}
////////////////////////////////////////////////////////////////////////
int check_specific_bit(int d_number, int order_of_bit)
{
    printf("\norder of %d bit from least significant bit is: %d", order_of_bit,(1&(d_number>>(order_of_bit-1))));
}