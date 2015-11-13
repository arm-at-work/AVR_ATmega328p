/*
 * Pins.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "Pins.h"

void Pins::pinsConfig(void) {
	DDRB |= (1 << DDB5 | 1 << DDB4 | 1 << DDB3); // pino como saída
	PORTB &= ~(1 << PB5 | 1 << PB4 | 1 << PB3); // estado lógico baixo
}
