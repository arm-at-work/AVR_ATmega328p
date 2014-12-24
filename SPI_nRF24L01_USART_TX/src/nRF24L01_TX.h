/*
 * nRF24L01.h
 *
 *  Created on: Nov 28, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef NRF24L01_TX_H_
#define NRF24L01_TX_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef SPI_H_
#include "SPI.h"
#endif

#ifndef F_CPU
#define F_CPU 16000000UL // CPU clock constant definition
#endif

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif

// nRF24L01 constants definition
#define CHANNEL 107 // channel selection - 1 to 126
#define ENDTX 75  // TX address - 1 to 255
#define ENDRX 75  // RX address - 1 to 255
#define BUFFER 4 // SPI buffer size

class nRF24L01_TX: public SPI {
public:
	volatile uint8_t dataSending[BUFFER];
	nRF24L01_TX() {
		this->dataSending[0] = 'l';
		this->dataSending[1] = 'm';
		this->dataSending[2] = 'n';
	}
	void config(void);
	void send(void);
};

#endif /* NRF24L01_H_ */
