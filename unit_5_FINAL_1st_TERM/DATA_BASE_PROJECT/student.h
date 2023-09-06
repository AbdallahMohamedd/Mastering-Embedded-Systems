/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_2********Topic:Student Data Base
File:fifo.h
*/

/*Header protection*/
#ifndef STUDENT_H_
#define STUDENT_H_
 
/*DEBUG*/
#define debug
#define yarab printf("@ Func: %s, File: %s, Line: %d \n", __func__, __FILE__, __LINE__);

/*Libraries used*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"
#include "conio.h"

/*Create structure to store student data*/
typedef struct
{
    char FIRST_NAME[50];
    char LAST_NAME[50];
    int ROLL;
    float GPA;
    int COURSE[10];
} S_STUDENTS_t;

/*Create structure to FIFO*/
typedef struct
{
    S_STUDENTS_t *base;
    S_STUDENTS_t *head;
    S_STUDENTS_t *tail;
    int counter;
    int length;
} S_FIFO_t;

/*Create enumeration to decelerate FIFO status*/
typedef enum
{
    LIST_no_error, // NO ERROR
    LIST_full,     // when reach 56th student
    LIST_empty,    // when try printing and list is empty
    LIST_Null      // when initialize LIST with empty data
} ENUM_LIST_STATUES_t;

S_STUDENTS_t STUDENT_ARRAY[55];
S_FIFO_t STUDENT_LIST;

/*API's student data base*/
void ADD_STUDENT_FILE_FUNC();
void ADD_STUDENT_MANUALLY_FUNC();
void FIND_STUDENT_BY_ROLL_FUNC();
void FIND_STUDENT_BY_1st_NAME_FUNC();
void FIND_STUDENT_BY_COURSE_FUNC();
void FIND_TOTAL_STUDENTS_FUNC();
void DELETE_STUDENT_BY_ROLL_FUNC();
void UPDATE_STUDENT_BY_ROLL_FUNC();
void SHOW_ALL_STUDENTS();
void FILL_STUDENT_DATA_FUNC(S_STUDENTS_t *);

/*LIST's  APIs*/
ENUM_LIST_STATUES_t INIT_LIST_FUNC(S_FIFO_t *fifo_info, S_STUDENTS_t *current_Student);
ENUM_LIST_STATUES_t ENqueue_LIST_FUNC(S_STUDENTS_t *); // push

#endif