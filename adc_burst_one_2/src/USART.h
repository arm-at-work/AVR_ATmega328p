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

/**
 * USART classe implements configuration and usage USART methods
 * @author Thiago  <thiagomallon@gmail.com>
 */
class USART {
public:
	/**
	 * @param void Method does not receive param
	 * @return void Method returns nothing
	 */
	void config(void);
	/**
	 * @param unsigned char data Char data to get sended to USART
	 * @return void Method returns nothing
	 */
	void send(unsigned char data);
	/**
	 * @param char const* charPtr Receive string pointer get sended to USART TX Buffer
	 * @return void Method returns nothing
	 */
	void printString(char const * charPtr);
};

#endif /* SRCUSART_H_ */
