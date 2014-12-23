/*
 * SPI.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SPI_H_
#include "SPI.h"
#endif

void SPI::config(void) {
	DDRB |= (SCK | MOSI | CSN | CE);
	DDRB &= ~MISO;
	DDRD &= ~IRQ;
	PORTD |= IRQ;

	SPCR |= (1 << MSTR); // master mode
	SPCR = ((SPCR & ~(1 << SPR0 | 1 << SPR1)) | (1 << SPI2X)); // SPI_CLK = Fosc / 2
	SPSR |= (1 << SPI2X); // SPI_CLK * 2

	PORTB |= CSN; // CSN on high, slave in stand-by
	PORTB &= ~CE; // CE on low, nRF24l01 off

	SPCR |= (1 << SPE); // enable SPI
}

uint8_t SPI::transmit(uint8_t data) {
	SPDR = data;
	do {
	} while (!(SPSR & (1 << SPIF)));
	return SPDR;
}
