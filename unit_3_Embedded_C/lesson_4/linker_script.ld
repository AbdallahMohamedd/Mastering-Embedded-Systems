/*
linker_Script.ld cortexM3
Eng. Abdullah Mohamed
Mastering Embedded system 
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
	sram(WRX) : ORIGIN = 0x20000000, LENGTH = 512M
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
	}>sram
}