/*
 * NRF24l01.h
 *
 *  Created on: Nov 28, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef NRF24L01RXTX_H_
#define NRF24L01RXTX_H_

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
#define BUFFER 2 // SPI buffer size

class NRF24l01RXTX: public SPI {
public:
	volatile uint8_t dataSending[BUFFER];
	volatile uint8_t receivedData[BUFFER];
	NRF24l01RXTX () {
		dataSending[0] = 0;
		receivedData[0] = 1;
	}
	void config(void);
	void send(void);
	void receive(void);
};

#endif /* NRF24L01RXTX_H_ */
