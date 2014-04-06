# C compiler
CC=avr-gcc
MMCU=atmega8
STD=c99
F_CPU=16000000L

# Programmer
PART=m8
PROGRAMMER=STK500

# Fuses
H_FUSE=0xdf
L_FUSE=0xef

DEFINES=F_CPU=$(F_CPU)
AVRFLAGS=-mmcu=$(MMCU)
CFLAGS=-std=$(STD) -Os
SOURCES=adc.c delay.c firmware.c motor.c ping.c shift.c sound.c
OBJECTS=$(SOURCES:.c=.o)

FUSE_CMD= avrdude -c $(PROGRAMMER) -p$(PART) -U hfuse:w:$(H_FUSE):m -U lfuse:w:$(L_FUSE):m
FLASH_CMD	= avrdude -c $(PROGRAMMER) -B 1 -p$(PART) -U flash:w:firmware.hex

install : fuse flash

firmware : firmware.elf
	avr-objcopy -j .text -j .data -O ihex firmware.elf firmware.hex

%.c : $.h

%.o : %.c
	$(CC) $(AVRFLAGS) -c -D $(DEFINES) $(CFLAGS) $< -o $@

firmware.elf: $(OBJECTS)
	$(CC) $(AVRFLAGS) -o firmware.elf $^

flash : firmware
	$(FLASH_CMD)

fuse:
	$(FUSE_CMD)

clean:
	rm -rf *.o *.elf *.hex
