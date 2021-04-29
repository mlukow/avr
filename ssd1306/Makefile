MCU = atmega328p
F_CPU = 16000000UL

CC = avr-gcc
CFLAGS = -std=c99 -Wall -g -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) \
	-ffunction-sections -fdata-sections -I. -Iu8g2/csrc \
	-Iu8g2/sys/avr/avr-libc/lib -DAVR_USE_HW_I2C
LDFLAGS = -Wl,--gc-sections -mmcu=$(MCU)
OBJCOPY = avr-objcopy

AVRDUDE = avrdude

PORT = /dev/cu.usbmodem142101
TARGET = main
SRCS = $(wildcard *.c u8g2/csrc/*.c u8g2/sys/avr/avr-libc/lib/avr-hw-i2c/*.c u8g2/sys/avr/avr-libc/lib/*.c)
OBJS = $(SRCS:.c=.o)

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) \
	-R .eeprom -R .fuse -R .lock -R .signature \
	-O ihex \
	$(TARGET).elf \
	$(TARGET).hex

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@

flash:
	$(AVRDUDE) -v -p $(MCU) -c arduino -P $(PORT) -D -U "flash:w:$(TARGET).hex:i"

clean:
	rm -rf $(TARGET).elf
	rm -rf $(TARGET).hex
	rm -rf $(OBJS)
