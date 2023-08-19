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
	}>flash

	.data :
	{
		*(.data*)
	}>flash

	.bss :
	{
		*(.bss*)
	}>sram
}