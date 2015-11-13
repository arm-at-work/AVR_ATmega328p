/*
 * ADC.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SRCADC_H_
#define SRCADC_H_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

/**
 * The ADC class implements ADC configuration.
 * @author Thiago  <thiagomallon@gmail.com>
 */
class ADC_ALL {
public:
	/**
	 * @param void Method don't receive params.
	 * @return void Return nothing.
	 */
	void config(void);
};

#endif /* SRCADC_H_ */
