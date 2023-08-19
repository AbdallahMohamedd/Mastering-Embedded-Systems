#include "Stdint.h"
extern int main(void);
extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

static unsigned long stack_top[256]; //256 * 4 =1024
void Rest_Handler	(void);
void Default_Handler(void)
{
	Rest_Handler();
}
void NMI_Handler         (void) __attribute__((weak,alias("Default_Handler")));;
void H_fault_Handler  	 (void) __attribute__((weak,alias("Default_Handler")));;
void MM_fault_Handler 	 (void) __attribute__((weak,alias("Default_Handler")));;
void Bus_fault           (void) __attribute__((weak,alias("Default_Handler")));;
void Usage_fault_Handler (void) __attribute__((weak,alias("Default_Handler")));;

void (*const g_p_fn_vectors[])() __attribute__((section(".vectors"))) = 
{
	(void(*)()) ((unsigned long)stack_top+sizeof(stack_top)),
	&Rest_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&MM_fault_Handler,
	&Bus_fault,
	&Usage_fault_Handler
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