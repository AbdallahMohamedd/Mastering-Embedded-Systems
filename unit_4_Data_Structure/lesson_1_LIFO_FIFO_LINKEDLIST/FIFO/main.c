/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 4********Lesson:1********Topic:FIFO "QUEUE"
File:main.c
*/

#include "fifo.h"
int main()
{
    S_FIFO_t UART_FIFO;
    DATA_TYPE buffer[5], i, temp;
    /*---------------> INITIALIZE FIFO <---------------*/
    if (INIT_FIFO_FUNC(&UART_FIFO, 5, buffer) == FIFO_no_error)
    {
        printf("INITIALZE FIFO IS DONE ;)\n\n");
    }
    /*---------------> ENQUEUE FIFO <---------------*/
    for (i = 0; i < 8; i++)
    {
        if (ENqueue_FIFO_FUNC(&UART_FIFO, i) == FIFO_no_error)
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
    PRINT_FIFO_FUNC(&UART_FIFO);
    /*---------------> DEQUEUE FIFO <---------------*/
    DEqueue_FIFO_FUNC(&UART_FIFO);
    DEqueue_FIFO_FUNC(&UART_FIFO);
    DEqueue_FIFO_FUNC(&UART_FIFO);
    /*---------------> PRINT FIFO <---------------*/
    PRINT_FIFO_FUNC(&UART_FIFO);
    /*---------------> ENQUEUE FIFO <---------------*/
    ENqueue_FIFO_FUNC(&UART_FIFO, (DATA_TYPE)9);
    printf("ENqueue FIFO IS DONE ;)\n");
    printf("\tENqueue (%X) item \n", (DATA_TYPE)9);
    ENqueue_FIFO_FUNC(&UART_FIFO, (DATA_TYPE)8);
    printf("ENqueue FIFO IS DONE ;)\n");
    printf("\tENqueue (%X) item \n", (DATA_TYPE)8);
    /*---------------> PRINT FIFO <---------------*/
    PRINT_FIFO_FUNC(&UART_FIFO);
    /*---------------> DEQUEUE FIFO <---------------*/
    DEqueue_FIFO_FUNC(&UART_FIFO);
    DEqueue_FIFO_FUNC(&UART_FIFO);
    /*---------------> PRINT FIFO <---------------*/
    PRINT_FIFO_FUNC(&UART_FIFO);

    return 0;
}