#include "uart.h"
unsigned char string_buffer1[100]= "learn-in-depth:Abdullah";
unsigned char const string_buffer2[100]="to create a rodata section";
void main(void)
{
	uart_send_string(string_buffer1);
}