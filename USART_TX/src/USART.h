/*
 * USART.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SRC_USARTH_
#define SRC_USARTH_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

class USART {
public:
	void config(void);
	void send(unsigned char data);
	void printString(char const * charPtr);
};

#endif /* SRC_USARTH_ */
