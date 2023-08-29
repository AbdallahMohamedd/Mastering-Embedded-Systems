/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:FIFO "QUEUE"
File:fifo.c
*/

#include "fifo.h"

ENUM_FIFO_STATUES_t INIT_FIFO_FUNC(S_FIFO_t *fifo_info, uint32_t length, DATA_TYPE *buffer)
{
    if (!buffer)
        return FIFO_Null;
    else
    {
        fifo_info->base = buffer;
        fifo_info->head = buffer;
        fifo_info->tail = buffer;
        fifo_info->counter = 0;
        fifo_info->length = length;
        return FIFO_no_error;
    }
}
/////////////////////////////////////////////////////////////////////////////////
ENUM_FIFO_STATUES_t ENqueue_FIFO_FUNC(S_FIFO_t *fifo_info, DATA_TYPE data) // push
{
    if (!fifo_info->base || !fifo_info->head || !fifo_info->tail)
        return FIFO_Null;
    else if (fifo_info->counter > fifo_info->length)
        return FIFO_full;
    else
    {
        *(fifo_info->head) = data;
        fifo_info->counter++;
        if (fifo_info->head == fifo_info->base + (fifo_info->length * sizeof(DATA_TYPE)))
            fifo_info->head = fifo_info->base;
        else
            fifo_info->head++;
        return FIFO_no_error;
    }
}
/////////////////////////////////////////////////////////////////////////////////
void PRINT_FIFO_FUNC(S_FIFO_t *fifo_info)
{
    DATA_TYPE *temp;
    if (!fifo_info->base || !fifo_info->head || !fifo_info->tail)
        printf("FIFO is NULL\n");
    else if (fifo_info->counter == 0)
        printf("FIFO is empty\n");
    else
    {
        printf("\n=========PRINT FIFO=========\n");
        temp = fifo_info->tail;
        for (int i = 0; i < fifo_info->counter; i++)
        {
            printf("              %d  \n", (DATA_TYPE)*temp);
            temp++;
        }
        printf("==============================\n");
    }
}
/////////////////////////////////////////////////////////////////////////////////
ENUM_FIFO_STATUES_t DEqueue_FIFO_FUNC(S_FIFO_t *fifo_info) // pop
{
    if (!fifo_info->head || !fifo_info->base || !fifo_info->tail)
    {
        printf("FIFO is NULL\n");
        return FIFO_Null;
    }
    else if (fifo_info->counter == 0)
    {
        printf("FIFO is empty\n");
        return FIFO_empty;
    }
    else
    {
        printf("DEQUEUE FIFO BY DATA: (%d)\n", *(fifo_info->tail));
        if (fifo_info->tail == (fifo_info->base + (fifo_info->length * sizeof(DATA_TYPE))))
        {
            fifo_info->tail = fifo_info->base;
        }
        else
        {
            fifo_info->tail++;
        }
        fifo_info->counter--;
        return FIFO_no_error;
    }
}