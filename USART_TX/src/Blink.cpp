/*
 * Blink.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "Blink.h"

// método configura pino
void Blink::blinkPinsConfig(void) {
	DDRB |= (1 << DDB5); // pino como saída
	PORTB &= ~(1 << PB5); // estado lógico baixo
}

