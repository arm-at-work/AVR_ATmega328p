/*
 * ADC.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "ADC_LIB.h"

/**
 * Method configures ADC.
 */
void ADC_LIB::ADCConfig(void) {
	ADCSRA |= (0b111 << ADPS0); //16Mhz/128 = 125Khz configuração do clock do ADC (não deve exceder 200Khz)
	ADMUX = ((ADMUX & ~(1 << REFS1)) | (1 << REFS0)); // Tensão de referência (Aref) em 5v
	ADMUX &= ~(0b1111 << MUX0); // Canal 0 (AD0) selecionado
	ADCSRA |= (1 << ADIE); // Habilita interrupção no ADC
	ADCSRA |= (1 << ADATE); // Modo burst
	ADCSRB &= ~(0b111 << ADTS0); // limpa bits ADTSn, selecionando-se modo burst
	ADCSRA |= (1 << ADEN); // Habilita ADC
	ADCSRA |= (1 << ADSC); // Realiza uma conversão inicial
}
