/*
Master Embedded Systems "learn in depth"
Eng.: Abdullah Mohamed
Unit 5********PROJECT_1********Topic:pressure detector project
File:startup.c
*/

#include "stdint.h"
#define STACK_START_SP 0x20001000
extern int main(void);
extern unsigned int stack_top;
extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;
void Rest_Handler(void);
void Default_Handler(void)
{
	Rest_Handler();
}


void NMI_Handler         (void) __attribute__((weak,alias("Default_Handler")));;
void H_fault_Handler  	 (void) __attribute__((weak,alias("Default_Handler")));;
void MM_fault_Handler 	 (void) __attribute__((weak,alias("Default_Handler")));;
void Bus_fault           (void) __attribute__((weak,alias("Default_Handler")));;
void Usage_fault_Handler (void) __attribute__((weak,alias("Default_Handler")));;
uint32_t vectors[] __attribute__((section(".vectors"))) = 
{
	(uint32_t) &stack_top,
	(uint32_t) &Rest_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Handler,
	(uint32_t) &Bus_fault,
	(uint32_t) &Usage_fault_Handler
};

void Rest_Handler(void)
{
	//copy data from ROM to RAM
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_TEXT;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;


	for(int i=0 ; i < DATA_size ; i++)
	{
		*((unsigned char*)P_dst++) =*((unsigned char*)P_src++);
	}


	//init the .bss with zero
	unsigned int bss_size = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS;
	P_dst = (unsigned char*)&_S_BSS;

	for(int i=0 ; i < bss_size ; i++)
	{
		*((unsigned char*)P_dst++) =(unsigned char)0;
	}


	//jump to main
	main();
}