#include <stdio.h>
#include <string.h>
void reverse(int data[], int length);
int main()
{
    int no=0,i=0;;
    int array[100];
    printf("Enter no. of element: ");
    scanf("%d",&no);
    printf("Input: ");
    while(i!=no)
    {
        scanf("%d",&array[i]);
        i++;
    }
    reverse(array,no);
}

void reverse(int data[], int length)
{
    for(int i=length-1; i>=0; i--)
    {
        printf("%d",data[i]);
    }
}