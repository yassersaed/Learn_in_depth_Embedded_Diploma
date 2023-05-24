CC=arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS= -I
LIBs=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)


all : cortex-m3lab.hex cortex-m3lab.bin

%.o : %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

%.o : %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

cortex-m3lab.elf : $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

cortex-m3lab.bin: cortex-m3lab.elf	
	$(CC)objcopy.exe -O binary $< $@
	
cortex-m3lab.hex: cortex-m3lab.elf
	$(CC)objcopy.exe -O binary $< $@

clean_all : 
	rm *.o *.elf *.bin *.map *.hex

clean: 
	em *.o *.elf