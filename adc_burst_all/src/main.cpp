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

#include <avr/interrupt.h>

// instancia classes
USART usart;
ADC_ALL adc_all;

int main(void) {
	adc_all.ADCConfig(); // método configura ADC
	usart.USARTConfig(); // método condigura USART
	sei(); // habilita interrupções globais
	do { // loop infinito
	} while (1);

	return 0;
}

ISR(ADC_vect) {
	static uint8_t channel = 0; // variável estática, para definição do canal a ser lido
	usart.USARTPutstring("\nReading channel ");
	usart.USARTSend('0' + channel); // Truque para quando queremos somente enviar um digito de 0 a 9
	usart.USARTPutstring(" : "); // Separação da label para o valor lido
	char buffer[5]; // armazena valor retornado pela função itoa
	itoa(ADCW, buffer, 10); // converte valor lido
	usart.USARTPutstring(buffer); // Envia valor convertido para o terminal

	ADMUX &= 0xF0; // Limpa bits de seleção de canal - canal 0 selecionado
	(channel < 5)? channel++ : channel = 0; // Reinicia channel caso variável > 5
	ADMUX |= channel; // Define o novo canal a ser lido
}
