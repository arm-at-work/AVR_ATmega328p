/*
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 *
 * Descrição: No arquivo implementa-se um pisca de led com o TIMER1 do ATmega328.
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
 *	 	alvo = (((16000000 / 256) / 50) -1) = 1249
 *
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif
#include <avr/interrupt.h>
#include "Pins.h"
#include "TIMER2.h"

// instancia classes
Pins pins;
TIMER2 timer2;

int main(void) {
	pins.pinsConfig();
	timer2.TIMER2Config();
	sei(); // habilita interrupções globais
	do {
	} while (1);
	return 0;
}

// interrupção por comparação do TIMER2
ISR(TIMER2_COMPA_vect) {
	static uint8_t counter = 0; // contador para interrupções do TIMER2
	// implementa counter forçado, para alcançarmos um delay de 500ms
	if (counter < 31) {
		counter++;
	} else {
		PORTB ^= (1 << PB5); // inverte estado lógico do pino
		counter = 0;
	}
}

//ISR(TIMER2_COMPA_vect) {
//		PORTB ^= (1 << PB5); // inverte estado lógico do pino
//}
