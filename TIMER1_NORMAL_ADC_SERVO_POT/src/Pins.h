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

/**
 * Pin class implements pins configurations
 * @author Thiago  <thiagomallon@gmail.com>
 */
class Pins {
public:
	/**
	 * @param void Method does not receive params
	 * @return void
	 */
	void pinsConfig(void);
};

#endif /* PINSH_ */
