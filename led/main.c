#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB = 0xff;
	while (1) {
		PORTB = 0b00100000;
		_delay_ms(100);
		PORTB = 0x00;
		_delay_ms(900);
	}
}
