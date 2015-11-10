/*
 * USART.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SRC_USART_H_
#define SRC_USART_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

class USART{
public:
	void USARTConfig(void);
	void USARTSend(unsigned char data);
	void USARTPutstring(char const * StringPtr);
};

#endif /* SRC_USART_H_ */
