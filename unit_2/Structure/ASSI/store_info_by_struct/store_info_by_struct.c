#include "stdio.h"
struct Sdata
{
    char name[50];
    int roll;
    float mark;
} student;
int main()
{
    printf("Enter information of student:\n");
    printf("Enter name: ");
    scanf("%s", student.name);
    printf("Enter roll number: ");
    scanf("%d", &student.roll);
    printf("Enter marks:");
    scanf("%f", &student.mark);
    printf("\nDisplaying information:");
    printf("\nName: %s", student.name);
    printf("\nRoll: %d", student.roll);
    printf("\nName: %f", student.mark);
}