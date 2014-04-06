#ifndef PING_H_
#define PING_H_
#include "common.h"
#include <avr/io.h>
#include <util/delay.h>


#define USTOCM(x) ( x/29/2 )
#define PINGP PORTC
#define PINGD DDRC
#define PINGPIN (1<<PC2)
#define PINGIN PINC



unsigned long pulseIn(unsigned long timeout);

unsigned long getDistanceCm();




#endif /* PING_H_ */
