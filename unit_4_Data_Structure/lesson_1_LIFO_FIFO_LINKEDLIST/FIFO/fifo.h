/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:FIFO "QUEUE"
File:fifo.h
*/

/*Header protection*/
#ifndef FIFO_H_
#define FIFO_H_


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"

/*
Select type of data you need, as (uint32_t, uint8_t, uint16_t)
*/
#define DATA_TYPE uint32_t

/*Create structure to decelerate FIFO */
typedef struct
{
    uint32_t length;
    uint32_t counter;
    DATA_TYPE *base;
    DATA_TYPE *head;
    DATA_TYPE *tail;
} S_FIFO_t;


/*Create enumeration to decelerate FIFO status*/
typedef enum
{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_Null
} ENUM_FIFO_STATUES_t;


/*FIFO  APIs*/
ENUM_FIFO_STATUES_t INIT_FIFO_FUNC(S_FIFO_t *,uint32_t,DATA_TYPE*);
ENUM_FIFO_STATUES_t ENqueue_FIFO_FUNC(S_FIFO_t *,DATA_TYPE);//push
ENUM_FIFO_STATUES_t DEqueue_FIFO_FUNC(S_FIFO_t *);//pop
void PRINT_FIFO_FUNC(S_FIFO_t *);


#endif