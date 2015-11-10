/*
 * ADC.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SRC_ADCH_
#define SRC_ADCH_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

class ADC_ALL{
public:
	void ADCConfig(void);
	uint16_t ADCRead(uint8_t channel);
};

#endif /* SRC_ADCH_ */
