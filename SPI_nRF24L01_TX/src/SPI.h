/*
 * SPI.h
 *
 *  Created on: Nov 28, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SPI_H_
#define SPI_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

// SPI pins contants definition
#define CE (1 << PB1)
#define CSN (1 << PB2)
#define MOSI (1 << PB3)
#define MISO (1 << PB4)
#define SCK (1 << PB5)
#define IRQ (1 << PD3)

class SPI {
public:
	void config(void);
	uint8_t transmit(uint8_t data);
};

#endif /* SPI_H_ */
