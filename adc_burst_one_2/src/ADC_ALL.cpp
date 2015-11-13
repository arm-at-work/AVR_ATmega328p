/*
 * ADC.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "ADC_ALL.h"

/**
 * Method configures ADC.
 */
void ADC_ALL::config(void) {
	ADCSRA |= (0b111 << ADPS0); //16Mhz/128 = 125Khz configuração do clock do ADC (não deve exceder 200Khz)
	ADMUX = ((ADMUX & ~(1 << REFS1)) | (1 << REFS0)); // Tensão de referência (Aref) em 5v
	ADMUX |= (1 << ADLAR); // result is left adjusted - necessary to get an 8-bit resolution
	ADMUX &= 0xF0; // Canal 0 selecionado
	ADCSRA |= (1 << ADIE); // Habilita interrupção no ADC
	ADCSRA |= (1 << ADATE); // Modo burst
	ADCSRB &= ~(0b111 << ADTS0); // limpa bits ADTSn, selecionando-se modo burst
	ADCSRA |= (1 << ADEN); // Habilita ADC
	ADCSRA |= (1 << ADSC); // Realiza uma conversão inicial

}
