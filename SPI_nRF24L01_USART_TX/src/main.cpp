/*
 * Created on: Dec 17, 2014
 *  Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _AVR_INTERRUPT_H_
#include <avr/interrupt.h>
#endif

#ifndef F_CPU
#define F_CPU 16000000UL // CPU clock constant definition
#endif

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif

#ifndef nRF24L01_TX_H_
#include "nRF24L01_TX.h"
#endif

#ifndef SRCPINS_H_
#include "Pins.h"
#endif

nRF24L01_TX nRF24L01;
Pins pins;

int main(void) {
	pins.ledConfig();
	pins.buttonConfig();
	pins.int1Init(); // inicializa o int0
	nRF24L01.config(); // inicializa o nRF24L01
	nRF24L01.send();
	sei();
	do {
	} while (1);
	return 1;
}

ISR(INT1_vect) {
	if (!(PIND & BUTTON)) {
		_delay_ms(25);
		if (nRF24L01.dataSending[0] == 'd') { // comando diminuir marcha
			PORTD |= LED;
			nRF24L01.dataSending[0] = 'l';
		} else if (nRF24L01.dataSending[0] == 'l') {
			PORTD &= ~LED;
			nRF24L01.dataSending[0] = 'd';
		}
		_delay_ms(150);
	}
	nRF24L01.send();
}
