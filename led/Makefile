MCU=atmega328p
F_CPU=16000000UL

CC=avr-gcc
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
OBJCOPY=avr-objcopy
RM=rm
RMFLAGS=-rf

PORT=/dev/cu.usbmodem142101
TARGET=avr
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.hex)

all: $(SRCS)
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
	${RM} ${RMFLAGS} ${TARGET}.bin

flash:
	avrdude -v -p ${MCU} -c arduino -P ${PORT} -D -U "flash:w:${TARGET}.hex:i"

clean:
	${RM} ${RMFLAGS} ${TARGET}.hex
	${RM} ${RMFLAGS} ${TARGET}.bin
