/*
 * ADC.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SRC_ADC_ALL_H_
#define SRC_ADC_ALL_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

class ADC_ALL {
public:
	void ADCConfig(void);
	uint16_t ADCRead(void);
};

#endif /* SRC_ADC_ALL_H_ */
