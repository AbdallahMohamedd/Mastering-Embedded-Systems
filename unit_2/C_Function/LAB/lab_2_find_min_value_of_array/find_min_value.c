#include <stdio.h>
#include <string.h>
int minno (int array[],int n);
int main()
{
    int n, data[50];
    printf("Enter number of element: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)  scanf("%d", &data[i]);
    printf("the data is ");
    for (int i = 0; i < n; i++)  printf("%d ", data[i]);
    printf("\n");
    //////////////////////////////////////////////////////////////
    printf("the min. no. in data is %d",minno (data,n));
}

int minno (int array[],int n)
{
    int min=array[0];
    for(int i=0; i<n; i++)
    {
        if(array[i]<min)
        {
            min=array[i];
        }
    }
    return min;
}