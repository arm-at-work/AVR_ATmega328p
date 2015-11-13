/*
 * USART.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "USART.h"

#ifndef F_CPU
#define F_CPU 16000000UL // define constante com clock de CPU
#endif

#define BAUDRATE 9600 // define BAUDRATE da USART
#define BAUDRATE_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1) // realiza os cálculos e atribui valor de prescaler à constante

// método configuração USART
void USART::USARTConfig(void) {
	UBRR0H = (uint8_t) (BAUDRATE_PRESCALLER >> 8); // seta valor do byte mais significativo
	UBRR0L = (uint8_t) (BAUDRATE_PRESCALLER); // seta valor do byte mais significativo
	UCSR0B = (1 << TXCIE0) | (1 << TXEN0); // habilita transferência e interrupção por transferência completa
	UCSR0C = (0b11 << UCSZ00); // frame de 8 bits
	UCSR0C &= ~(1 << USBS0); // 1 bit de parada
	UCSR0C &= ~(0b11 << UMSEL00); // modo assíncrono
	UCSR0C &= ~(0b11 << UPM00); // sem paridade
}

void USART::USARTSend(unsigned char data) {
	do { // aguarda até que buffer TX esteja vazio (até UDR0 possa receber novos dados)
	} while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data; // coloca novo pacote no buffer de transferência
}

void USART::USARTPutstring(char const * StringPtr) {
	while (*StringPtr != 0x00) {
		USARTSend(*StringPtr);
		StringPtr++;
	}
}




