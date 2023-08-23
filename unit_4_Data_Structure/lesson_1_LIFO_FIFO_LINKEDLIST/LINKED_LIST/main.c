/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:linked list
File:main.c
*/

#include "linked_list.h"

int main()
{
    char temp_text[40];
    while (1)
    {
        printf("\n==========================================================\n");
        printf("Choose one of the following option:\n");
        printf("1)Add student  \n");
        printf("2)Delete student  \n");
        printf("3)View all list  \n");
        printf("4)Delete all student  \n");
        gets(temp_text);
        printf("==========================================================\n");
        switch (atoi(temp_text))
        {
        case 1:
            ADD_STUDENT_FUN();
            break;
        case 2:
            DELETE_STUDENT_FUN();
            break;
        case 3:
            VIEW_ALL_LIST_FUN();
            break;
        case 4:
            DELETE_ALL_FUN();
            break;
        default:
            printf("\n Wrong option  :(");
            break;
        }
    }
}