/*
 * Pins.h
 *
 *  Created on: Nov 22, 2015
 r      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef PINSH_
#define PINSH_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

class Pins {
public:
	void PCINT0Config(void);
	void PCINT1Config(void);
	void PCINT2Config(void);
	void ledsConfig(void);
};

#endif /* PINSH_ */
