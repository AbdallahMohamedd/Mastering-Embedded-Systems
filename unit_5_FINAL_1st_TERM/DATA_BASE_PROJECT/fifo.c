/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_2********Topic:Student Data Base
File:fifo.c
*/ 

#include "student.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*FIFO  APIs*/
ENUM_LIST_STATUES_t INIT_LIST_FUNC(S_FIFO_t *STUDENT_LIST, S_STUDENTS_t *STUDENT_ARRAY)
{

    if (!STUDENT_ARRAY)
    {
        printf("LIST IS NOT INITALIZE!! \n");
        printf("Please TRY AGAIN!! \n");
        return LIST_Null;
    }
    else
    {
        STUDENT_LIST->base = STUDENT_ARRAY;
        STUDENT_LIST->head = STUDENT_ARRAY;
        STUDENT_LIST->tail = STUDENT_ARRAY;
        STUDENT_LIST->counter = 0;
        STUDENT_LIST->length = 55;
        return LIST_no_error;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ENUM_LIST_STATUES_t ENqueue_LIST_FUNC(S_STUDENTS_t *new_student) // push
{
    if (!STUDENT_LIST.base || !STUDENT_LIST.head || !STUDENT_LIST.tail)
    {
        printf("Sorry the list is NULL!!");
        return LIST_Null;
    }
    else if (STUDENT_LIST.counter > STUDENT_LIST.length)
    {
        printf("Sorry the list is FULL!!");
        return LIST_full;
    }
    else
    {
        int flag = 1;
        int c = 0;
        while (c < STUDENT_LIST.counter)
        {
            if (new_student->ROLL == STUDENT_ARRAY[c].ROLL)
            {
                printf("[ERROR] Roll number (%d) is already taken\n", new_student->ROLL);
                printf("[INFO] Student Details is NOT added successfully\n");
                flag = 0;
                break;
            }
            c++;
        }
        if (flag)
        {
            *(STUDENT_LIST.head) = *(new_student);
            STUDENT_LIST.counter++;
            if (STUDENT_LIST.head == STUDENT_LIST.base + (STUDENT_LIST.length * sizeof(S_STUDENTS_t)))
                STUDENT_LIST.head = STUDENT_LIST.base;
            else
                STUDENT_LIST.head++;
            printf("[INFO] Student Details is added successfully\n");
        }
        FIND_TOTAL_STUDENTS_FUNC();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////