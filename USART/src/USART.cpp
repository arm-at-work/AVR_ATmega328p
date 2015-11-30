/*
 * USART.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "USART.h"

#ifndef F_CPU
#define F_CPU 16000000UL // defines CPU clock's constant
#endif

#define BAUDRATE 9600 // define USART BAUDRATE
#define BAUDRATE_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1) // make calcs and set prescaler value to the constant

/**
 * Method configs USART operation
 */
void USART::USARTConfig(void) {
  UBRR0H = (uint8_t) (BAUDRATE_PRESCALLER >> 8);  // seta valor do byte mais significativo
  UBRR0L = (uint8_t) (BAUDRATE_PRESCALLER);  // seta valor do byte mais significativo
  UCSR0B = (1 << TXCIE0) | (1 << TXEN0);  // habilita transferência e interrupção por transferência completa
  UCSR0C = (0b11 << UCSZ00);  // frame de 8 bits
  UCSR0C &= ~(1 << USBS0);  // 1 bit de parada
  UCSR0C &= ~(0b11 << UMSEL00);  // modo assíncrono
  UCSR0C &= ~(0b11 << UPM00);  // sem paridade
}

/**
 * Method puts chars on USART TX buffer
 */
void USART::USARTSend(unsigned char data) {
  do {  // aguarda até que buffer TX esteja vazio (até UDR0 possa receber novos dados)
  } while (!(UCSR0A & (1 << UDRE0)));
  UDR0 = data;  // coloca novo pacote no buffer de transferência
}

/**
 * Method prints a byte as binary
 */
void USART::byteAsBinary(unsigned char c) {
  for (int i = 7; i >= 0; --i) {
    this->USARTSend((c & (1 << i)) ? '1' : '0');
  }
  this->USARTSend('\n');
}

/**
 * Method prints two bytes as binary
 */
void USART::twoBytesAsBinary(unsigned short c) {
  for (int i = 15; i >= 0; --i) {
    this->USARTSend((c & (1 << i)) ? '1' : '0');
    if (i % 8 == 0) {
      this->USARTSend('\n');
    }
  }
}

