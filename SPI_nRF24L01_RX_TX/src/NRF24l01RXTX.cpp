/*
 * NRF24l01.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef NRF24L01RXTX_H_
#include "NRF24l01RXTX.h"
#endif

void NRF24l01RXTX::config(void) {
	SPI::config(); // initialize SPI

	//	RX_ADDR_P0 - configura endere�o de recep��o PIPE0
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

	//CONFIG - transmission mode
	PORTB &= ~CSN;
	SPI::transmit(0x20);
	SPI::transmit(0b00001110);
	PORTB |= CSN;

	//tempo para sair do modo standby entrar em modo de recep�ao
	PORTB |= CE;
	_delay_us(15);
	PORTB &= ~CE;
}

void NRF24l01RXTX::send(void) {
	//STATUS - clear register
	PORTB &= ~CSN;
	SPI::transmit(0x27);
	SPI::transmit(0b01110000);
	PORTB |= CSN;

	//TX_FLUSH - limpa o buffer FIFO TX
	PORTB &= ~CSN;
	SPI::transmit(0xE1);
	PORTB |= CSN;

	PORTB &= ~CSN;
	SPI::transmit(0xA0);
	static uint8_t i;
	for (i = 0; i < BUFFER; i++) {
		SPI::transmit(this->dataSending[i]);
	}
	PORTB |= CSN;

	// pulse to transmit data
	PORTB |= CE;
	_delay_us(15);
	PORTB &= ~CE;

	_delay_ms(5);
}

void NRF24l01RXTX::receive(void) {

	// STATUS - clear register
	PORTB &= ~CSN;
	SPI::transmit(0x27);
	SPI::transmit(0x70);
	PORTB |= CSN;

	// LIMPA FLUSH_RX
	PORTB &= ~CSN;
	SPI::transmit(0xE2);
	PORTB |= CSN;

	//R_RX_PAYLOAD - receive data from FIFO RX buffer
	PORTB &= ~CSN;
	SPI::transmit(0x61);
	static uint8_t i;
	for (i = 0; i < BUFFER; i++) {
		this->receivedData[i] = SPI::transmit(0xFF);
	}
	PORTB |= CSN;

	_delay_us(15);
}
