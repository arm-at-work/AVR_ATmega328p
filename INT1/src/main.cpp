/*
 * main.cpp
 *
 *  Created on: Nov 24, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 *
 * Implemento uso de Interrupções Externas pelo registrador INT1. A vantagem da interrupção externa pelo INT1 é que pode-se
 * configurar em qual borda ou estado será gerada a interrupção através dos bits ISC10 e ISC11 do registrador EICRA, porém,
 * a interrupção externa do INT1 resume a apenas o pino PD3.
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _AVR_INTERRUPT_H_
#include <avr/interrupt.h>
#endif

#ifndef PINSH_
#include "Pins.h"
#endif

Pins pins;

int main(void) {
	pins.buttonConfig(); // método configura pinos de botões
	pins.ledConfig(); // método configura pino de led
	sei();
	// habilita interrupções globais
	do {
	} while (1);
	return 0;
}

ISR(INT1_vect) {
	PORTB ^= (1 << PB5); // inverte estado lógico do pino
}

