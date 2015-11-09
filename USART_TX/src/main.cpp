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

#include "Blink.h"
#include "USART.h"

// Instância classes
Blink blink;
USART usart;

char Message[] = "Jehovah's world\n";  // string de mensagem

int main(void) {
  blink.blinkPinsConfig();  // método configuração pino
  usart.config();  // método configuração USART
  sei();
  // habilita interrupções globais
  while (1) {
    usart.printString(Message);  // imprime string
    _delay_ms(1000);  // implementa delay de 1 seg.
  }
}

// Interrupção por envio de pacote da USART
ISR(USART_TX_vect) {
  PORTB ^= (1 << PB5);  // inverte estado lógico do pino
}
