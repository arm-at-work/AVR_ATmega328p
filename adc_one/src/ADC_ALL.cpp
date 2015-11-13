/*
 * ADC.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#include "ADC_ALL.h"

void ADC_ALL::ADCConfig(void) {
	ADCSRA |= (0b111 << ADPS0); //16Mhz/128 = 125Khz configuração do clock do ADC (não deve exceder 200Khz)
	ADMUX = ((ADMUX & ~(1 << REFS1)) | (1 << REFS0)); // Tensão de referência (Aref) em 5v
	ADCSRA |= (1 << ADEN); // Habilita ADC
	ADCSRA |= (1 << ADSC); // Realiza uma conversão inicial
}

uint16_t ADC_ALL::ADCRead(void) {
	ADMUX &= 0xF0; // Limpa seleção de canais (limpa bits de seleção de canal)
	ADCSRA |= (1 << ADSC); // Inicia uma nova conversão
	do { // Aguarda até que conversão seja finalizada (bit é colocado em 0 quando finaliza conversão)
	} while (ADCSRA & (1 << ADSC));
	return ADCW; // Retorna valor lido do canal selecionado
}
