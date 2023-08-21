/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4      lesson:1        topic:LIFO "STACK"
File:main.c
*/
#include "stdio.h"
#include "lifo.h"

int main()
{
    sLIFO_INFO_t UART_LIFO;
    uint32_t i, size = 5, temp;
    uint32_t buffer_1[size];
    INIT_LIFO_FUN(&UART_LIFO, &buffer_1[0], size);

    for (i = 0; i < size; i++)
    {
        if (PUSH_LIFO_FUN(&UART_LIFO, i) == LIFO_no_error)
            printf("push %d item to UART_LIFO\n", i);
    }

    for (i = 0; i < size; i++)
    {
        if (POP_LIFO_FUN(&UART_LIFO, &temp) == LIFO_no_error)
            printf("pop %d item to UART_LIFO\n", temp);
    }

    return 0;
}