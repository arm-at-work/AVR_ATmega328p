/**
 * @file main.cpp
 *
 * Created on: Nov 27, 2015
 * @author Thiago  <thiagomallon@gmail.com>
 *
 * In this project is showned how to print a byte as binary. It's useful to
 * discover if something is wrong with a register configuration, to take binary values from
 * decimal, etc.
 */

#ifndef _AVR_IO_H_
#include <avr/io.h>
#endif

#ifndef _UTIL_DELAY_H_
#include <util/delay.h>
#endif

#include "USART.h"

// instantiate class
USART usart;

int main(void) {
  usart.USARTConfig(); // method configures USART
  do {
    usart.byteAsBinary(UCSR0C); // call binary conversor method and pass an USART register, to check its configuration
    _delay_ms(500);
  } while (1);
  return 0;
}
