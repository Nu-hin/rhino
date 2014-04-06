#ifndef SOUND_H_
#define SOUND_H_

#include "common.h"
#include "delay.h"
#include <avr/io.h>


#define SOUND_PORT PORTB
#define SOUND_PORTD DDRB
#define SOUND (1<<PB3)

void initSound();
void beep(const int duration_ms);
void soundOn();
void soundOff();

#endif /* SOUND_H_ */
