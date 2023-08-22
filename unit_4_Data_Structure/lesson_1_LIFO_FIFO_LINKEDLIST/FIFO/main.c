/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:FIFO "QUEUE"
File:main.c
*/

#include "fifo.h"

int main()
{
    element_type i;
    element_type temp;
    sFIFO_t FIFO_UART;
    element_type BUFFER_UART[5];
    /*---------------> INITIALIZE FIFO <---------------*/
    if (FIFO_no_error == INIT_FIFO_FUN(&FIFO_UART, BUFFER_UART, 5))
    {
        printf("INITIALZE FIFO IS DONE ;)\n\n");
    }
    /*---------------> ENQUEUE FIFO <---------------*/
    for (i = 0; i < 5; i++)
    {
        if (ENqueue_FIFO_FUN(&FIFO_UART, i) == FIFO_no_error)
        {
            printf("ENqueue FIFO IS DONE ;)\n");
            printf("\tENqueue (%d) item \n", i);
        }
        else
        {
            printf("ENqueue FIFO IS FULL :(\n");
            printf("ENqueue FIFO IS FUILED :(\n");
        }
    }
    /*---------------> PRINT FIFO <---------------*/
    PRINT_FIFO_FUN(&FIFO_UART);
    /*---------------> DEQUEUE FIFO <---------------*/
    DEqueue_FIFO_FUN(&FIFO_UART, &temp);
    printf("DEQUEUE FIFO BY DATA: (%d)\n", temp);
    DEqueue_FIFO_FUN(&FIFO_UART, &temp);
    printf("DEQUEUE FIFO BY DATA: (%d)\n", temp);
    DEqueue_FIFO_FUN(&FIFO_UART, &temp);
    printf("DEQUEUE FIFO BY DATA: (%d)\n", temp);
    /*---------------> PRINT FIFO <---------------*/
    PRINT_FIFO_FUN(&FIFO_UART);
    /*---------------> ENQUEUE FIFO <---------------*/           
    ENqueue_FIFO_FUN(&FIFO_UART, (element_type)9);
    printf("ENqueue FIFO IS DONE ;)\n");
    printf("\tENqueue (%X) item \n", (element_type)9);
    ENqueue_FIFO_FUN(&FIFO_UART, (element_type)8);
    printf("ENqueue FIFO IS DONE ;)\n");
    printf("\tENqueue (%X) item \n", (element_type)8);
    /*---------------> PRINT FIFO <---------------*/
    PRINT_FIFO_FUN(&FIFO_UART);

    return 0;
}