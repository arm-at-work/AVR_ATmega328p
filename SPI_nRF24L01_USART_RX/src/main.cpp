/*
 * Created on: Dec 17, 2014
 *  Author: Thiago Mallon <thiagomallon@gmail.com> 
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _AVR_INTERRUPT_H_
#include <avr/interrupt.h>
#endif

#ifndef F_CPU
#define F_CPU 16000000UL // CPU clock constant definition
#endif

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif

#ifndef nRF24L01_RX_H_
#include "nRF24L01_RX.h"
#endif

#ifndef SRCPINS_H_
#include "Pins.h"
#endif

//#ifndef SRCUSART_H_
//#include "USART.h"
//#endif

nRF24L01_RX nRF24L01;
Pins pins;
//USART mallonUSART;

int main(void) {
	pins.ledConfig();
	pins.buttonConfig();
	pins.int1Init(); // inicializa o int0
//	mallonUSART.config(); // inicializa o int0
	nRF24L01.config(); // inicializa o nRF24L01
	nRF24L01.receive();
	sei();
	do {
	} while (1);
	return 1;
}

ISR(INT1_vect) {
	if (nRF24L01.receivedData[0] == 'd') {
//		mallonUSART.printBuffer(nRF24L01.receivedData);
//		mallonUSART.sendBuffer('\n');
		PORTD &= ~LED;
	} else if (nRF24L01.receivedData[0] == 'l') {
//		mallonUSART.printBuffer(nRF24L01.receivedData);
//		mallonUSART.sendBuffer('\n');
		PORTD |= LED;
	}
	nRF24L01.receive();
}
