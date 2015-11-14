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
	DDRB |= (0b11 << DDB1); // pinos como saída
	PORTB |= (0b11 << PB1); // estado lógico baixo
}
