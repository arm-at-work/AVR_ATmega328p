/*
 * Pins.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "Pins.h"

/**
 * Method configures SERVO pin
 */
void Pins::pinsConfig(void) {
	DDRB |= (1 << DDB1); // pinos como saída
	PORTB |= (1 << PB1); // estado lógico baixo
}
