/*
 * Pins.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "Pins.h"

void Pins::pinsConfig(void) {
	DDRB |= (1 << DDB5); // pino como saída
	PORTB &= ~(1 << PB5); // estado lógico baixo
}

