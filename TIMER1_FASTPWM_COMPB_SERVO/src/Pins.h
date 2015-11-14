/*
 * Pins.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef PINSH_
#define PINSH_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

class Pins {
public:
	void pinsConfig(void);
};

#endif /* PINSH_ */
