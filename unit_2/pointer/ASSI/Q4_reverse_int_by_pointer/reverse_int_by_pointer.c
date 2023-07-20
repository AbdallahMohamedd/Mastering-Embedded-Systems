#include "stdio.h"
#include "string.h"
#pragma psck(1)
int main()
{
    int total, arr[50], i;
    int *p_arr = arr;
    printf("Enter total number: ");
    scanf("%d", &total);
    for (i = 0; i < total; i++)
    {
        printf("Element number(%d): ", i + 1);
        scanf("%d", p_arr);
        p_arr++;
    }
    printf("The elements of array with reverse order are \n");
    i = total;
    p_arr--;
    do
    {
        printf("Element number(%d): %d \n", i, *p_arr);
        p_arr--;
        i--;
    } while (i > 0);
}