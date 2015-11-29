/*
 * Pins.h
 *
 *  Created on: Nov 24, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef PINS_H_
#define PINS_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

class Pins {
public:
	void buttonConfig(void);
	void ledConfig(void);
};

#endif /* PINS_H_ */
