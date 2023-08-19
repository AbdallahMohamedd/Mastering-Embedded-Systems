/*
linker_Script.ld cortexM3
Eng. Abdullah Mohamed
Mastering Embedded system 
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(WRX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_TEXT = . ;
	}>flash

	.data :
	{
		_S_DATA = . ;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = . ;
	}>sram AT> flash

	.bss :
	{
		_S_BSS = . ;
		*(.bss*)
		_E_BSS = . ;
		. = ALIGN(4);
		. = . + 0x1000;
		stack_top = . ;
	}>sram
}