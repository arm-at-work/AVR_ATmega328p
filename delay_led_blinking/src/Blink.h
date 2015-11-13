/*
 * Blink.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef BLINK_H_
#define BLINK_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

// declara classe
class Blink {
public:
	void blinkPinsConfig(void); // método de configuração de pino para led
};

#endif /* BLINK_H_ */
