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

#include "TIMER1.h"

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

void TIMER1::TIMER1Config(void) {
	TCCR1A &= ~(0b11 << WGM10); // timer em modo NORMAL
	TCCR1B &= ~(0b11 << WGM12); // timer em modo NORMAL
	TCCR1B = ((TCCR1B & ~(0b11 << CS10)) | (1 << CS12)); // prescaler de 256
	TIMSK1 |= (1 << TOIE1); // habilita interrupção por estouro do contador
	TCNT1 = 34286; /* seta valor de início para contador do timer, para que atinjamos o intervalo desejado.
	 Cálculo:
	 Frequência para 500ms: ((1 / 500) * 1000) = 2
	 65535 - (((16000000 / 256) / ((1 / 500) * 1000) −1) = 34286 */
}
