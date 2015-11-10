/*
 * main.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif

#ifndef _AVR_INTERRUPT_H_
#include <avr/interrupt.h>
#endif

#include "USART.h"
// Instância classes
USART usart;

int main(void) {
	usart.USARTConfig();
	sei(); // função da biblioteca que habilita interrupções globais
	do {
	} while (1);
}

// Interrupção por envio de pacote da USART
ISR(USART_RX_vect) {
	PORTB ^= (1 << PB5); // inverte estado lógico do pino
}
