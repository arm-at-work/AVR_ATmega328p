/*
 * main.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */
#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif
#include "Blink.h"

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif


// Instância Blink
Blink blink;

int main(void) {
	blink.blinkPinsConfig(); // método que configura pino
	while (1) {
		PORTB ^= (1 << PB5); // inverte nível lógico do pino
		_delay_ms(500); // implementa delay de 1 seg.
	}
}
