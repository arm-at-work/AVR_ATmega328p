/*
 * Pins.cpp
 *
 *  Created on: Nov 24, 2015
 *      Author: Thiago  <thiagomallon@gmail.com>
 */

#ifndef PINS_H_
#include "Pins.h"
#endif

/**
 * buttonsConfig method sets up INT0 configs.
 */
void Pins::buttonConfig(void) {
	DDRD &= ~(1 << DDD2); // pino como entrada
	PORTD |= (1 << PD2); // nível lógico alto
	EIMSK |= (1 << INT0); // habilita interrupções externas do INT0 (pino PD2)
	EICRA = ((EICRA & ~(1 << ISC00)) | (1 << ISC01)); // interrupção no INT0 será por borda de descida
}

void Pins::ledConfig(void) {
	DDRB |= (1 << DDB5); // pino como saída
	PORTB |= (1 << PB5); // nível lógico alto
}
