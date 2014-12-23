/*
 * Pins.h
 *
 *  Created on: Dec 1, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SRCPINS_H_
#define SRCPINS_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#define LED (1 << PD7) // led pin

class Pins {
public:
	void int1Init(void);
	void ledConfig(void);
};

#endif /* SRCPINS_H_ */
