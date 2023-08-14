#@copyright: Abdullah Mohamed
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
PROJECT_NAME=learn_in_depth

all: $(PROJECT_NAME).bin
	@echo "=================> Build Done <================="
	@echo " :') "

startup.o: startup.s
	$(CC)as.exe -o0 $(INCS) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c -o0 $(INCS) $(CFLAGS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm *.elf *.bin

clean_all:
	rm *.elf *.bin *.o 