/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:linked list
File:linked_list.h
*/

/*Header protection*/
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/*Add library which used in project*/
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "stdio.h"

/*Effective data*/
typedef struct
{
    char name[60];
    uint16_t ID;
    float height;
} S_data;

/*Linked list Node*/
struct S_NODE_STUDENT
{
    S_data current_student;
    struct S_NODE_STUDENT *P_NEXT_STUDENT;
} ;

/*API's*/
void ADD_STUDENT_FUNC(void);
int DELETE_STUDENT_FUNC(void);
void VIEW_ALL_LIST_FUNC(void);
void DELETE_ALL_FUNC(void);
int GET_SPECIFIC_NODE_FUNC (void);
int GET_SPECIFIC_NODE_FROM_END_FUNC(void);
int The_number_of_students_in_the_list_FUNC(void);
#endif