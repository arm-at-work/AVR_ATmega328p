/*
 * Pins.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 *
 */

#include "Pins.h"

void Pins::PCINT1Config(void) {
	DDRC &= ~(1 << DDC5); // configura pino como entrada
	PORTC |= (1 << PC5); // atribui nível lógico alto ao pino (pino entrada e nível lógico alto = pull-up habilitado)
	PCICR |= (1 << PCIE1); // habilita interrupções no PORTC;
	PCMSK1 |= (1 << PCINT13); // habilita interrupção por mudança no pino PC5 (PCINT13);
}

void Pins::ledConfig(void) {
	DDRB |= (1 << DDB5); // configura pino como saída
	PORTB &= ~(1 << PB5); // estado lógico baixo
}
