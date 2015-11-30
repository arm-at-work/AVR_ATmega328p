/*
 * USART.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Thiago Mallon <thiagomallon@gmail.com>
 */

#ifndef SRC_USARTH_
#define SRC_USARTH_

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

/**
 * USART class implements USART configs and usage.
 * @author Thiago  <thiagomallon@gmail.com>
 */
class USART {
public:
  /**
   * @param void Method doesn't receives params
   * @return void Method doesn't returns values
   */
	void USARTConfig(void);
  /**
   * @param unsigned char data Method receives char value
   * @return void Method doesn't returns values
   */
	void USARTSend(unsigned char data);
  /**
   * @param unsigned char data Method receives char value
   * @return void Method doesn't returns values
   */
	void byteAsBinary(unsigned char c);
  /**
   * @param unsigned short data Method receives char value
   * @return void Method doesn't returns values
   */
	void twoBytesAsBinary(unsigned short c);
};

#endif /* SRC_USARTH_ */
