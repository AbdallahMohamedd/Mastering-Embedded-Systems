#include "stdio.h"
#include "string.h"
struct information 
{
    int roll;
    char name[100];
    float mark;
}student[10];
int main()
{
    char ch;
    printf("Enter information of student\n");
    int i=1;
    do 
    {
        student[i].roll=i;
        printf("For Roll number:%d\n",i);
        printf("Enter Name:");
        scanf("%s",student[i].name);
        printf("Enter mark: ");
        scanf("%f",&student[i].mark);
        i++;
    }while(i<11);
    printf("************Displaying Data************\n");
    for(int i=1;i<11;i++)
    {
    printf("Information for roll number: %d\n",student[i].roll);
    printf("Name: %s\n",student[i].name);
    printf("Mark: %0.2f\n",student[i].mark);
    printf("______________________________________________\n");
    } 
}