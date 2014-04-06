#ifndef SHIFT_H_
#define SHIFT_H_

#include "common.h"
#include <avr/io.h>
static unsigned char SHIFT_REGISTER = 0x00;



#define SHIFT_CLOCK (1<<PD4)
#define SHIFT_LATCH (1<<PD3)
#define SHIFT_DATA  (1<<PD2)
#define SHIFT_PORT PORTD
#define SHIFT_PORTD DDRD



void setByte(const unsigned char a);
void initShift();






#endif
