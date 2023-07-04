#include "stdio.h"
#include "string.h"
void reverse(int number[], int size);
int main()
{
    int number[10000];
    int size;
    printf("Enter, size of array: ");
    scanf("%d", &size);
    printf("Enter, Input array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &number[i]);
    reverse(number, size);
}

void reverse(int number[], int size)
{
    printf("The reverse array is: ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", number[i]);
    }
}