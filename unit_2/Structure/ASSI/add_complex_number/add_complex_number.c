#include "stdio.h"
struct complex add_complex_number(struct complex num1, struct complex num2);
struct complex
{
    float real;
    float img;
} num1, num2, sum;
int main()
{
    printf("Enter 1st number(R then IMG): ");
    scanf("%f %f", &num1.real, &num1.img);
    printf("Enter 2nd number(R then IMG): ");
    scanf("%f %f", &num2.real, &num2.img);
    add_complex_number(num1, num2);
}
struct complex add_complex_number(struct complex num1, struct complex num2)
{
    sum.real = num1.real + num2.real;
    sum.img = num1.img + num2.img;
    printf("sum = %0.1f+j%0.1f", sum.real, sum.img);
    return sum;
}
