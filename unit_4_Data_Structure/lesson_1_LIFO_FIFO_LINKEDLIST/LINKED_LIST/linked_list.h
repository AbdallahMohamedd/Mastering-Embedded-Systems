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
#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "conio.h"

/*Effective data*/
struct Sdata
{
    int ID;
    char name[50];
    float height;
};

/*Linked list Node*/
struct SStudent
{
    struct Sdata current_student;
    struct SStudent *p_Next_student;
};

/*API's*/
void ADD_STUDENT_FUN(void);
int DELETE_STUDENT_FUN(void);
void VIEW_ALL_LIST_FUN(void);
void DELETE_ALL_FUN(void);

#endif