/*
 * Pins.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 *
 */

#include "Pins.h"

void Pins::PCINT2Config(void) {
	DDRD &= ~(1 << DDD4); // configura pino como entrada
	PORTD |= (1 << PD4); // atribui nível lógico alto ao pino (pino entrada e nível lógico alto = pull-up habilitado)
	PCICR |= (1 << PCIE2); // habilita interrupções no PORTD;
	PCMSK2 |= (1 << PCINT20); // habilita interrupção por mudança no pino PD4 (PCINT20);
}

void Pins::ledConfig(void) {
	DDRB |= (1 << DDB5); // configura pino como saída
	PORTB &= ~(1 << PB5); // estado lógico baixo
}
