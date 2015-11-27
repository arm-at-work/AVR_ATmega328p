/*
 * main.cpp
 *
 *  Created on: Nov 22, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 *
 * A interrupção por mudança de estado de pino (PCINT) não permite configuração da borda na qual deseja-se ser
 * disparada a exceção (diferentemente da Interrupções Externas), porém na ISR do arquivo presente, exemplifico
 * como obter relativa filtragem para a borda desejada. A vantagem das interrupções por mudança de estado de
 * pino (Pin Change Interrupt) é que existe a possibilidade de se trabalhar com quase todos os pinos do microcontrolador,
 * sendo que as interrupções externas (INT0 e INT1) somente permitem dois pinos PD2 (INT0) e PD3 (INT1).
 *
 * O registrador de controle de interrupção por mudança de estado de pino PCICR possui três bits de controle para
 * cada porta do ATmega328, que são: PCIE0 (PORTB), PCIE1 (PORTC) e PCIE2 (PORTD). Da mesma forma exitem três
 * registradores para habilitação de interrupção individual de pino para cada porta, que são: PCMSK0<0:7> (pinos do PORTB),
 * PCMSK1<0:6> (pinos do PORTC) e PCMSK2<0:7> (pinos do PORTD). A configuração de interrupção, por exemplo, para o pino PB0 do
 * PORTB, seria a atribuição de 1 para o bit PCINT0 do registrador PCMSK0, para o pino ṔB1, seria setando o bit PCINT1 e assim
 * sucessivamente.
 *
 * No presente arquivo queremos uma interrupção para o pino PC5, sendo assim, setamos o bit PCINT13 do registrador PCMSK1, além
 * de setarmos o bit PCIE1 do registrador PCICR.
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _AVR_INTERRUPT_H_
#include <avr/interrupt.h>
#endif

#include "Pins.h"

Pins pins;

int main(void) {
	pins.PCINT1Config(); // inicializa a interrupção por mudança no pino
	pins.ledConfig(); // configura pino de led
	sei();
	// habilita interrupções globais
	do { // loop infinito
	} while (1);
	return 0;
}

ISR(PCINT1_vect) {
	PCIFR &= ~(1 << PCIF1); // seta flag de interrupção em andamento, para impedir que muitas interrupções sejam geradas
	if (!(PINC & (1 << PINC5))) { // verifica se a mudança foi para estado lógico baixo
		PORTB ^= (1 << PB5); // inverte estado lógico do pino
	}
	PCIFR |= (1 << PCIF1); // limpa flag de interrupção
}
