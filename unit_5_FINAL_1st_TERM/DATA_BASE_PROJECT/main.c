/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_2********Topic:Student Data Base
File:main.c
*/
#include "student.h"
#include "student.c"
#include "fifo.c"
int main()
{
    if (INIT_LIST_FUNC(&STUDENT_LIST, &STUDENT_ARRAY[0]) == LIST_no_error)
    {
        int OPTION;
        while (1)
        {
            printf("\n==========================================================\n");
            printf("\nChoose one of the following Options \n");
            printf("\n1: Add Students data from a file");
            printf("\n2: Add Students data manually");
            printf("\n3: Find a student by his roll number");
            printf("\n4: Find a student by his first name");
            printf("\n5: Find all the students in a specific course");
            printf("\n6: Get the total number of students");
            printf("\n7: Delete a student by his roll number");
            printf("\n8: Update a student's data");
            printf("\n9: Show all the students data");
            printf("\n0: Exit\n");
            printf("        -----        \n");
            printf("Enter your choice to perform the task: ");
            scanf("%d", &OPTION);
            printf("==========================================================\n");
            switch (OPTION)
            {
            case 1:
                ADD_STUDENT_FILE_FUNC();
                break;
            case 2:
                ADD_STUDENT_MANUALLY_FUNC();
                break;
            case 3:
                FIND_STUDENT_BY_ROLL_FUNC();
                break;
            case 4:
                FIND_STUDENT_BY_1st_NAME_FUNC();
                break;
            case 5:
                FIND_STUDENT_BY_COURSE_FUNC();
                break;
            case 6:
                FIND_TOTAL_STUDENTS_FUNC();
                break;
            case 7:
                DELETE_STUDENT_BY_ROLL_FUNC();
                break;
            case 8:
                UPDATE_STUDENT_BY_ROLL_FUNC();
                break;
            case 9:
                SHOW_ALL_STUDENTS();
                break;
            case 0:
                return 0;
            default:
                printf("\n Wrong option  :(");
                break;
            }
        }
    }
}
