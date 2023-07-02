#include <stdio.h>
#include <string.h>
void swap(int aa[], int ssaa, int bb[], int ssbb);
int main()
{
    int a[100], b[100], sa = 0, sb = 0;
    printf("Enter no. of element of 1st array: ");
    scanf("%d", &sa);
    printf("Enter no. of element of 2nd array: ");
    scanf("%d", &sb);
    printf("Input 1st array: ");
    for (int i = 0; i < sa; i++)
        scanf("%d", &a[i]);
    printf("Input 2nd array: ");
    for (int i = 0; i < sb; i++)
        scanf("%d", &b[i]);
    swap(a, sa, b, sb);
}
void swap(int aa[], int ssaa, int bb[], int ssbb)
{
    int temp[100];
    for (int i = 0; i < ssaa; i++)
        temp[i] = aa[i];
    for (int i = 0; i < ssbb; i++)
        aa[i] = bb[i];
    for (int i = 0; i < ssaa; i++)
        bb[i] = temp[i];
    printf("\nthe 1st array is: ");
    for (int i = 0; i < ssbb; i++)
        printf("%d ", aa[i]);
    printf("\nthe 2nd array is: ");
    for (int i = 0; i < ssaa; i++)
        printf("%d ", bb[i]);
}