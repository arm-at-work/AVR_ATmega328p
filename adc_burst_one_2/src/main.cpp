/*
 * main.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif

#ifndef SRCUSART_H_
#include "USART.h"
#endif

#ifndef SRCADC_H_
#include "ADC_ALL.h"
#endif

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif

#ifndef _AVR_INTERRUPT_H_
#include <avr/interrupt.h>
#endif

USART usart;
ADC_ALL adc_all;

int main(void) {
	adc_all.config(); // método configura ADC
	usart.config(); // método condigura USART
	sei(); // habilita interrupções globais
	do { // loop infinito
	} while (1);

	return 0;
}

ISR(ADC_vect) {
	usart.printString("\nReading channel ");
	usart.printString(" : "); // Separação da label para o valor lido
//	char buffer[5]; // armazena valor retornado pela função itoa
//	itoa(ADCW, buffer, 10); // converte valor lido
	char buffer[4]; // armazena valor retornado pela função itoa
	itoa(ADCH, buffer, 8); // converte valor lido
	usart.printString(buffer); // Envia valor convertido para o terminal
}
