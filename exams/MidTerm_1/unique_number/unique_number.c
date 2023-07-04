#include "stdio.h"
#include "string.h"
int find_unique_number(int series[], int size);
int main()
{
    int size;
    int series[100];
    printf("Enter total number of series: ");
    scanf("%d", &size);
    printf("Enter the series: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &series[i]);
    printf("The unique number is: %d", find_unique_number(series, size));
}
int find_unique_number(int series[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int k = 0; k < size; k++)
        {
            if (i == k)
                continue;
            else
            {
                if (series[i] == series[k])
                    break;
                else if (series[i] != series[k])
                {
                    if (k == size - 1)
                        return series[i];
                    else
                        continue;
                }
            }
        }
    }
}