# avr-skeleton

Example project for ATmega328P-PU based Arduino UNO. It flashes the L LED built into the development board every second for 100ms.

If you want to use a different microcontroller, change the parameters in the `Makefile` file.

## Requirements

In order to be able to build and run this project, you need the following installed:
* avr-gcc
* avrdude

To install the dependcies on MacOS, make sure you have [Homebrew](https://brew.sh) installed in your system, and then run:

```sh
brew tap osx-cross/avr
brew install avr-gcc
brew install avrdude
```

## Building

Build the project by executing `make` command in the root directory of the project.

Example output:

```sh
localhost% make
avr-gcc -std=c99 -Wall -g -Os -mmcu=atmega328p -DF_CPU=16000000UL -I. -o avr.bin main.c
avr-objcopy -j .text -j .data -O ihex avr.bin avr.hex
rm -rf avr.bin
```

# Running

In order to run the program on the microcontroller, you need to flash it:

```sh
localhost% make flash
avrdude -v -p atmega328p -c arduino -P /dev/cu.usbmodem142101 -D -U "flash:w:avr.hex:i"

avrdude: Version 6.3, compiled on Nov 16 2020 at 16:16:00
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "/etc/avrdude.conf"
         User configuration file is "/Users/mlukow/.avrduderc"
         User configuration file does not exist or is not a regular file, skipping
		 
         Using Port                    : /dev/cu.usbmodem142101
         Using Programmer              : arduino
         AVR Part                      : ATmega328P
         Chip Erase delay              : 9000 us
         PAGEL                         : PD7
         BS2                           : PC2
         RESET disposition             : dedicated
         RETRY pulse                   : SCK
         serial program mode           : yes
         parallel program mode         : yes
         Timeout                       : 200
         StabDelay                     : 100
         CmdexeDelay                   : 25
         SyncLoops                     : 32
         ByteDelay                     : 0
         PollIndex                     : 3
         PollValue                     : 0x53
         Memory Detail                 :
		 
                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           eeprom        65    20     4    0 no       1024    4      0  3600  3600 0xff 0xff
           flash         65     6   128    0 yes     32768  128    256  4500  4500 0xff 0xff
           lfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           hfuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           efuse          0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           lock           0     0     0    0 no          1    0      0  4500  4500 0x00 0x00
           calibration    0     0     0    0 no          1    0      0     0     0 0x00 0x00
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00

         Programmer Type : Arduino
         Description     : Arduino
         Hardware Version: 3
         Firmware Version: 4.4
         Vtarget         : 0.3 V
         Varef           : 0.3 V
         Oscillator      : 28.800 kHz
         SCK period      : 3.3 us
		 
avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.01s

avrdude: Device signature = 0x1e950f (probably m328p)
avrdude: safemode: hfuse reads as 0
avrdude: safemode: efuse reads as 0
avrdude: reading input file "avr.hex"
avrdude: writing flash (180 bytes):

Writing | ################################################## | 100% 0.04s

avrdude: 180 bytes of flash written
avrdude: verifying flash memory against avr.hex:
avrdude: load data flash data from input file avr.hex:
avrdude: input file avr.hex contains 180 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.03s

avrdude: verifying ...
avrdude: 180 bytes of flash verified

avrdude: safemode: hfuse reads as 0
avrdude: safemode: efuse reads as 0
avrdude: safemode: Fuses OK (E:00, H:00, L:00)

avrdude done.  Thank you.

localhost%
```
