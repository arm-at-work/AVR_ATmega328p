/*
 * Pins.cpp
 *
 *  Created on: Nov 24, 2015
 r      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef PINSH_
#include "Pins.h"
#endif

/**
 * buttonsConfig method sets up INT0 configs.
 */
void Pins::buttonConfig(void) {
	DDRD &= ~(1 << DDD3 | 1 << DDD2); // pinos como entrada
	PORTD |= (1 << PD3 | 1 << PD2); // nível lógico alto
	EIMSK |= (1 << INT1 | 1 << INT0); // habilita interrupções externas do INT1 (pino PD3) e INT0 (pino PD2)
	EICRA = ((EICRA & ~(1 << ISC10 | 1 << ISC00)) | (1 << ISC11 | 1 << ISC01)); // interrupção no INT0 e INT1 serão por borda de descida
}

void Pins::ledConfig(void) {
	DDRB |= (1 << DDB5 | 1 << DDB4); // pinos como saída
	PORTB |= (1 << PB5 | 1 << PB4); // nível lógico alto
}
