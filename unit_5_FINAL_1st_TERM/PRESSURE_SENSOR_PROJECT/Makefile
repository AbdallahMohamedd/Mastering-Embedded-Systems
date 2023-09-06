#@copyright: Abdullah Mohamed
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 
INCS=-I .
LIBS=
SRC=$(wildcard src/*.c)
OBJ=$(SRC:src/%.c=obj/%.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
PROJECT_NAME=bin/P1_High_Pressure_Detector

all: $(PROJECT_NAME).bin
	@echo "=================> Build Done <================="
	@echo " :') "
  
obj/%.o: src/%.c
	$(CC)gcc.exe -c -O0 $(INCS) $(CFLAGS) -mthumb -std=c99 $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=bin/Map_file.map

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm bin/*.elf bin/*.bin

clean_all:
	rm obj/*.o bin/*.elf bin/*.bin