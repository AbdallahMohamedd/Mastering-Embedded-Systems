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
        printf("Choose one of the following opti on:\n");
        printf("1)Add student  \n");
        printf("2)Delete student  \n");
        printf("3)View all list  \n");
        printf("4)Delete all student  \n");
        printf("5)Select specific student  \n");
        printf("6)Select specific student from end \n");
        printf("7)The number of students in the list \n");
        gets(temp_text);
        printf("==========================================================\n");
        switch (atoi(temp_text))
        {
        case 1:
            ADD_STUDENT_FUNC();
            break;
        case 2:
            DELETE_STUDENT_FUNC();
            break;
        case 3:
            VIEW_ALL_LIST_FUNC();
            break;
        case 4:
            DELETE_ALL_FUNC();
            break;
        case 5:
            GET_SPECIFIC_NODE_FUNC();
            break;
        case 6:
            GET_SPECIFIC_NODE_FROM_END_FUNC();
            break;
        case 7:
            printf("The number of students in the list = %d !!", The_number_of_students_in_the_list_FUNC());
            break;
        default:
            printf("\n Wrong option  :(");
            break;
        }
    }
}