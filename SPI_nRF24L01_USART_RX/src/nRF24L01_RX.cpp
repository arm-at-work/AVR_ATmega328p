/*
 * nRF24L01.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef nRF24L01_TX_H_
#include "nRF24L01_RX.h"
#endif

void nRF24L01_RX::config(void) {
	SPI::config(); // initialize SPI

	//RX_ADDR_P0 - configura endere�o de recep��o PIPE0
	PORTB &= ~CSN;
	SPI::transmit(0x2A);
	SPI::transmit(ENDRX);
	SPI::transmit(0xC2);
	SPI::transmit(0xC2);
	SPI::transmit(0xC2);
	SPI::transmit(0xC2);
	PORTB |= CSN;

	//TX_ADDR - configura endere�o de transmiss�o
	PORTB &= ~CSN;
	SPI::transmit(0x30);
	SPI::transmit(ENDTX);
	SPI::transmit(0xC2);
	SPI::transmit(0xC2);
	SPI::transmit(0xC2);
	SPI::transmit(0xC2);
	PORTB |= CSN;

	//EN_AA - habilita autoACK no PIPE0
	PORTB &= ~CSN;
	SPI::transmit(0x21);
	SPI::transmit(0x01);
	PORTB |= CSN;

	//EN_RXADDR - ativa o PIPE0
	PORTB &= ~CSN;
	SPI::transmit(0x22);
	SPI::transmit(0x01);
	PORTB |= CSN;

	//SETUP_AW - define o endere�o com tamanho de 5 Bytes
	PORTB &= ~CSN;
	SPI::transmit(0x23);
	SPI::transmit(0x03);
	PORTB |= CSN;

	//SETUP_RETR - configura para nao retransmitir pacotes
	PORTB &= ~CSN;
	SPI::transmit(0x24);
	SPI::transmit(0x00);
	PORTB |= CSN;

	//RF_CH - define o canal do modulo (TX e RX devem ser iguais)
	PORTB &= ~CSN;
	SPI::transmit(0x05);
	SPI::transmit(CHANNEL);
	PORTB |= CSN;

	//RF_SETUP - ativa LNA, taxa em 250K, e maxima potencia 0dbm
	PORTB &= ~CSN;
	SPI::transmit(0x26);
	SPI::transmit(0b00100110);
	PORTB |= CSN;

	//STATUS - reseta o resgistrador STATUS
	PORTB &= ~CSN;
	SPI::transmit(0x27);
	SPI::transmit(0x70);
	PORTB |= CSN;

	//RX_PW_P0 - tamanho do buffer PIPE0
	PORTB &= ~CSN;
	SPI::transmit(0x31);
	SPI::transmit(BUFFER);
	PORTB |= CSN;

	//CONFIG - coloca em modo de recep��o, e define CRC de 2 Bytes
	PORTB &= ~CSN;
	SPI::transmit(0x20);
	SPI::transmit(0x0F);
	PORTB |= CSN;

	//tempo para sair do modo standby entrar em modo de recep�ao
	PORTB |= CE;
	_delay_us(15);
}

void nRF24L01_RX::receive(void) {

	// STATUS - clear register
	PORTB &= ~CSN;
	SPI::transmit(0x27);
	SPI::transmit(0x70);
	PORTB |= CSN;

	//R_RX_PAYLOAD - receive data from FIFO RX buffer
	PORTB &= ~CSN;
	SPI::transmit(0x61);
	static uint8_t i;
	for (i = 0; i < BUFFER; i++) {
		this->receivedData[i] = SPI::transmit(0xFF);
	}
	PORTB |= CSN;

	// LIMPA FLUSH_RX
	PORTB &= ~CSN;
	SPI::transmit(0xE2);
	PORTB |= CSN;

	_delay_us(15);
}
