/*
 * Pins.cpp
 *
 *  Created on: Nov 24, 2015
 :      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef PINSH_
#include "Pins.h"
#endif

/**
 * buttonsConfig method sets up INT0 configs.
 */
void Pins::buttonConfig(void) {
	DDRD &= ~(1 << DDD3); // pino como entrada
	PORTD |= (1 << PD3); // nível lógico alto
	EIMSK |= (1 << INT1); // habilita interrupções externas do INT1 (pino PD3)
	EICRA = ((EICRA & ~(1 << ISC10)) | (1 << ISC11)); // interrupção no INT0 será por borda de descida
}

void Pins::ledConfig(void) {
	DDRB |= (1 << DDB5); // pino como saída
	PORTB |= (1 << PB5); // nível lógico alto
}
