/*
 * Blink.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef BLINKH_
#define BLINKH_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

// declara classe
class Blink {
public:
	void blinkPinsConfig(void); // método para configuração do pino
};

#endif /* BLINKH_ */
