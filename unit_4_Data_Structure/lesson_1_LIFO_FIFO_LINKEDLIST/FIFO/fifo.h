/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:FIFO "QUEUE"
File:fifo.h
*/

/*Header protection*/
#ifndef FIFO_H_
#define FIFO_H_
#include <stdint.h>
#include <stdio.h>

/*
Select type of data you need, as (uint32_t, uint8_t, uint16_t)
*/
#define element_type uint8_t


/*Create structure to decelerate FIFO */
typedef struct
{
	uint32_t length;
	uint32_t counter;
	element_type *base;
	element_type *tail;
	element_type *head;
} sFIFO_t;


/*Create enumeration to decelerate FIFO status*/
typedef enum
{
	FIFO_no_error,
	FIFO_empty,
	FIFO_full,
	FIFO_Null
} eFIFO_STATUS;

/*FIFO  APIs*/
eFIFO_STATUS INIT_FIFO_FUN(sFIFO_t *fifo_info, element_type *buffer, uint32_t length);
eFIFO_STATUS ENqueue_FIFO_FUN(sFIFO_t *fifo_info, element_type item);
eFIFO_STATUS DEqueue_FIFO_FUN(sFIFO_t *fifo_info, element_type *item);
eFIFO_STATUS FIFO_STATUS(sFIFO_t *fifo_info);
void PRINT_FIFO_FUN(sFIFO_t *fifo_info);

#endif