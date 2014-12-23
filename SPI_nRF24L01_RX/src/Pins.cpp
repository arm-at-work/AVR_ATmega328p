/*
 * Pins.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: Thiago Mallon  <thiagomallon@gmail.com>
 */

#ifndef SRCPINS_H_
#include "Pins.h"
#endif

void Pins::int1Init(void) {
	DDRD &= ~(1 << DDD3);
	PORTD &= ~(1 << PD3);

	EICRA |= (1 << ISC11);
	EICRA &= ~(1 << ISC10);

	EIMSK |= (1 << INT1);
}

void Pins::ledConfig(void) {
	DDRD |= LED;
	PORTD &= ~LED;
}
