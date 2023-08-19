#@copyright: Abdullah Mohamed
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
PROJECT_NAME=learn_in_depth_cortex_m4

all: $(PROJECT_NAME).bin
	@echo "=================> Build Done <================="
	@echo " :') "

%.o: %.c
	$(CC)gcc.exe -c -O0 $(INCS) $(CFLAGS) -mthumb -std=c99 $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=map_file.map
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.bin

clean_all:
	rm *.elf *.bin *.o *.axf *.map