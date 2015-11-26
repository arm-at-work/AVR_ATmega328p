/*
 * Pins.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 *
 */

#include "Pins.h"

void Pins::PCINT0Config(void) {
	DDRB &= ~(1 << DDB1); // configura pino como entrada
	PORTB |= (1 << PB1); // atribui nível lógico alto ao pino (pino entrada e nível lógico alto = pull-up habilitado)
	PCICR |= (1 << PCIE0); // habilita interrupções no PORTB;
	PCMSK0 |= (1 << PCINT1); // habilita interrupção por mudança no pino PB1 (PCINT1);
}

void Pins::ledConfig(void) {
	DDRB |= (1 << DDB5); // configura pino como saída
	PORTB &= ~(1 << PB5); // estado lógico baixo
}
