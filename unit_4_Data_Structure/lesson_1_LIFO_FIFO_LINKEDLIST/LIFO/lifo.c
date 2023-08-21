/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4      lesson:1        topic:LIFO "STACK"
File:lifo.c
*/
#include "lifo.h"

eLIFO_STATUS_t INIT_LIFO_FUN(sLIFO_INFO_t *lifo_info, uint32_t *buffer, uint32_t length)
{
    if (!buffer) // buffer==null
        return LIFO_Null;
    lifo_info->base = buffer;
    lifo_info->head = buffer;
    lifo_info->counter = 0;
    lifo_info->length = length;
    return LIFO_no_error;
}

eLIFO_STATUS_t POP_LIFO_FUN(sLIFO_INFO_t *lifo_info, uint32_t *item)
{
    if (!lifo_info->base || !lifo_info->head)
        return LIFO_Null;

    if (lifo_info->counter == 0)
        return LIFO_empty;

    lifo_info->head--;
    *item = *(lifo_info->head);
    lifo_info->counter--;
    return LIFO_no_error;
}

eLIFO_STATUS_t PUSH_LIFO_FUN(sLIFO_INFO_t *lifo_info, uint32_t item)
{
    if (lifo_info->counter == lifo_info->length)
        return LIFO_full;
    *(lifo_info->head) = item;
    lifo_info->head++;
    lifo_info->counter++;
    return LIFO_no_error;
}