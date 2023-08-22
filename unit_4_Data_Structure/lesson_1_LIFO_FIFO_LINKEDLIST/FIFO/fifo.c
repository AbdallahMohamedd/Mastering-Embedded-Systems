/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:FIFO "QUEUE"
File:fifo.c
*/

#include "fifo.h"

eFIFO_STATUS INIT_FIFO_FUN(sFIFO_t *fifo_info, element_type *buffer, uint32_t length)
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
//////////////////////////////////////////////////////////////////////////////////////
// feh hna e5tlaf m3ah fe el pointer bta3 el item
eFIFO_STATUS ENqueue_FIFO_FUN(sFIFO_t *fifo_info, element_type item)
{
    if (!fifo_info->base || !fifo_info->head || !fifo_info->tail)
        return FIFO_Null;
    else if (fifo_info->counter > fifo_info->length)
        return FIFO_full;
    else
    {
        *(fifo_info->head) = item;
        fifo_info->counter++;
        if (fifo_info->head == (fifo_info->base + (fifo_info->length * sizeof(element_type))))
        {
            fifo_info->head = fifo_info->base;
        }
        else
        {
            fifo_info->head++;
        }
        return FIFO_no_error;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
eFIFO_STATUS DEqueue_FIFO_FUN(sFIFO_t *fifo_info, element_type *item)
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
        *item = *(fifo_info->tail);
        if (fifo_info->tail == (fifo_info->base + (fifo_info->length - 1)))
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
/////////////////////////////////////////////////////////////////////////////////////////
eFIFO_STATUS FIFO_STATUS(sFIFO_t *fifo_info);
/*
me to me: sorry ya abdullah lm tege t2ra el code da tany ana kslt aktb el func. de :( 
*/
/////////////////////////////////////////////////////////////////////////////////////////
void PRINT_FIFO_FUN(sFIFO_t *fifo_info)
{
    if (!fifo_info->base || !fifo_info->head || !fifo_info->tail)
        printf("FIFO is NULL\n");
    else if (fifo_info->counter == 0)
    {
        printf("FIFO is empty\n");
    }
    else
    {
        printf("\n=========PRINT FIFO=========\n");
        element_type *temp = fifo_info->tail;
        for (int i = 0; i < fifo_info->counter; i++)
        {
            printf("              %d  \n", (element_type)*temp);
            temp++;
        }
        printf("==============================\n");
    }
}