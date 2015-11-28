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

void Pins::PCINT1Config(void) {
	DDRC &= ~(1 << DDC5); // configura pino como entrada
	PORTC |= (1 << PC5); // atribui nível lógico alto ao pino (pino entrada e nível lógico alto = pull-up habilitado)
	PCICR |= (1 << PCIE1); // habilita interrupções no PORTC;
	PCMSK1 |= (1 << PCINT13); // habilita interrupção por mudança no pino PC5 (PCINT13);
}

void Pins::PCINT2Config(void) {
	DDRB &= ~(1 << DDB1); // configura pino como entrada
	PORTD |= (1 << PD4); // atribui nível lógico alto ao pino (pino entrada e nível lógico alto = pull-up habilitado)
	PCICR |= (1 << PCIE2); // habilita interrupções no PORTD;
	PCMSK2 |= (1 << PCINT20); // habilita interrupção por mudança no pino PD4 (PCINT20);
}

void Pins::ledsConfig(void) {
	DDRB |= (0b111 << DDB3); // pinos como saída
	PORTB &= ~(0b111 << PB3); // estado lógico baixo
}
