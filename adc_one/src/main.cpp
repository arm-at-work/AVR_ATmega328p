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

#include "USART.h"
#include "ADC_ALL.h"

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif


USART usart;
ADC_ALL adc_all;

uint16_t adcValue; // armazena valor lido do canal ADC
char buffer[5]; // armazena valor retornado pela função itoa

int main(void) {
	adc_all.ADCConfig(); // método configura ADC
	usart.USARTConfig(); // método condigura USART

	do {
		usart.USARTPutstring("\nReading channel ");
		usart.USARTPutstring(" : "); // Separação da label para o valor lido
		adcValue = adc_all.ADCRead(); // Lê valor do canal e colova valor em adcValue
		itoa(adcValue, buffer, 10); // Converte o valor lido para string ASCII
		usart.USARTPutstring(buffer); // Envia valor convertido para o terminal
		_delay_ms(500); // implementa delay de meio segundo
	} while (1);

	return 0;
}
