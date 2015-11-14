/**
 * @file main.cpp
 * Created on: Nov 8, 2015
 * @author Thiago  <thiagomallon@gmail.com>
 *
 * @PROJECT_BRIEF "No arquivo implementa-se um pisca de led com o TIMER1 do ATmega328.
 *
 * Cálculos relevantes:
 *
 * Resolução máxima do MCU (1/F_CPU):
 * - O ATmega328 posui clock de 16Mhz, logo o cálculo para se saber a resolução máxim, é: 1 / 16000000 = 0,0000000625seg
 * - O valor obtido 0,0000000625 é o tempo de um ciclo de máquina, ou seja, para cada ciclo o MCU gasta 0,0000000625 segundos.
 *
 * Intervalo máximo obtido pelos timers:
 * - O ATmega328 possui três timers, sendo o TIMER1 de 16 bits e os TIMER0 e TIMER2 de 8 bits.
 * - TIMER1: possui contagem máxima de 65535
 * - TIMER0 e TIMER2: possuem contagem máxima de 255
 * - Calculamos acima, a resolução máxima do ATmega328 como é de 0,0000000625, sendo assim, para identificarmos
 * o intervalo máximo possível, utilizando o prescaler 1, com o TIMER1 (16 bits), podemos utilizar o seguinte
 * cálculo: 0,0000000625 * 65535 = 0,0040959375s, ou seja, pouco mais de 4ms. Já para
 * os TIMER0 e TIMER2: 0,0000000625 * 255 = 0,000015938.
 * - Utilizando o prescaler dos Timers, podemos aumentar esse valor. Sabemos que o TIMER1 possui os prescalers 1, 8, 64,
 * 256, 1024, sendo assim, com o prescaler 1024 poderemos alcançar um intervalo máximo de: (1024 / 16000000) * 65535 = 4,19424,
 * ou seja, um pouco mais de 4 segundos. Já para os Timers de 8 bits esse valor seria: (1024 / 16000000) * 255 = 0,01632, ou
 * seja, pouco mais de 16ms.
 *
 * Contador alvo do timer (((F_CPU / Prescaler) / Target Frequency) - 1):
 * - Quando estamos utilizando o timer no modo comparador, precisamos setar o valor do comparador do timer, para podermos
 * gerar uma exceção e então realizarmos a ação desejada. Exemplo:
 *
 * 	Caso queiramos um intervalo de 20ms, com o TIMER1 do ATmega328, devemos empregar os seguintes cálculos:
 *
 * 	- calcula-se a frequência, para o valor em milisegundos que desejamos:
 * 		frequencia = (1 / 20) * 10000 = 50Hz
 *
 * 	- Levando-se em conta que temos um clock de 16Mhz, escolhemos um prescaler de 256 e a frequência alvo é de 50Hz:
 *	 	alvo = (((16000000 / 256) / 50) -1) = 1249"
 *
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _AVR_INTERRUPT_H_
#include <avr/interrupt.h>
#endif

#ifndef _STDLIB_H_
#include <stdlib.h>
#endif

#include "Pins.h"
#include "TIMER1.h"
#include "ADC_LIB.h"

// instancia classes
Pins pins;
TIMER1 timer1;
ADC_LIB adc;

/**
 * Method initializes application.
 * @param void Method does not receive params
 * @return int
 */
int main(void) {
	timer1.tc1Count = 60536;

	pins.pinsConfig(); // method configures servo pins
	timer1.TIMER1Config(); // method configures timer operation
	adc.ADCConfig(); // method configures adc operation
	/* enable global interrupt */
	sei();
	do {
	} while (1);
	return 0;
}

/**
 * Interrupt Service Routine do TIMER1
 * @param vector TIMER_COMPA_vect Interrupt to be treated
 */
ISR(TIMER1_COMPA_vect) {
	PORTB &= ~(1 << PB1); // puts pin on low logic state
}

/**
 * Interrupt Service Routine do TIMER1
 * @param vector TIMER_COMPB_vect Interrupt to be treated
 */
ISR(TIMER1_COMPB_vect) {
	PORTB &= ~(1 << PB2); // puts pin on low logic state
}

/**
 * Interrupt Service Routine do TIMER1
 * @param vector TIMER_OVF_vect Interrupt to be treated
 */
ISR(TIMER1_OVF_vect) {
	PORTB |= (0b11 << PB1); // puts pin on high logic state
	TCNT1 = timer1.tc1Count; // set timer count
}

/**
 * Interrupt Service Routine do ADC
 * @param vector ADC_vect Interrupt to be treated
 */
ISR(ADC_vect) {
	static uint8_t channel = 0; // channel selector
	if (channel == 1) { // checks if selected channel is 1
		OCR1A = (ADCW * 0.6745) + timer1.tc1Count; // update timer comparator value according to readed pot value
		ADMUX &= ~(1 << MUX0); // channel 0 (AD0) selected
		channel = 0; // next will be channel 0
	} else {
		OCR1B = (ADCW * 0.6745) + timer1.tc1Count; // update timer comparator value according to readed pot value
		ADMUX |= (1 << MUX0); // Channel 1 (AD1) selected
		channel = 1; // next will be channel 1
	}
}
