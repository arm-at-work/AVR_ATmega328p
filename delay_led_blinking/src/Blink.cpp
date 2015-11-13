/*
 * Blink.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "Blink.h"

// implementa método que configura pino como saída, bem como atribui estado lógico baixo
void Blink::blinkPinsConfig(void) {
	DDRB |= (1 << DDB5);
	PORTB &= ~(1 << PB5);
}

