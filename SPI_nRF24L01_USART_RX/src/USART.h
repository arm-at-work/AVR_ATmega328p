/*
 * USART.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SRCUSART_H_
#define SRCUSART_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

class USART {
public:
	void config(void);
	void send(unsigned char data);
	void sendBuffer(uint8_t data);
	void printString(char const * charPtr);
	void printBuffer(volatile uint8_t * charPtr);
};

#endif /* SRCUSART_H_ */
