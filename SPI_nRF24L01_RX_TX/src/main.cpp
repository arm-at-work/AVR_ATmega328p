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

#ifndef NRF24L01RXTX_H_
#include "NRF24l01RXTX.h"
#endif

#ifndef SRCPINS_H_
#include "Pins.h"
#endif

NRF24l01RXTX nRF24l01;
Pins pins;

int main(void) {
	pins.ledConfig();
	pins.buttonConfig();
	pins.int1Init(); // inicializa o int0
	nRF24l01.config(); // inicializa o nRF24L01
	nRF24l01.send();
	sei();
	do {
	} while (1);
	return 1;
}

ISR(INT1_vect) {
	if (!(PIND & BUTTON)) {
		_delay_ms(25);
		if (!nRF24l01.dataSending[0]) { // comando diminuir marcha
			PORTD |= LED;
			nRF24l01.dataSending[0] = 1;
		} else {
			PORTD &= ~LED;
			nRF24l01.dataSending[0] = 0;
		}
		_delay_ms(150);
	}
	nRF24l01.send();
}
