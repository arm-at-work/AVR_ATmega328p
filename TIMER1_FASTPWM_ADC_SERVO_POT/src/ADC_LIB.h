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

/**
 * The ADC class implements ADC configuration.
 * @author Thiago  <thiagomallon@gmail.com>
 */
class ADC_LIB {
public:
	/**
	 * @param void Method don't receive params.
	 * @return void Return nothing.
	 */
	void ADCConfig(void);
};

#endif /* SRC_ADCH_ */
