#ifndef MOTORH_H_
#define MOTORH_H_
#include "common.h"
#include <avr/io.h>

#define MOT1AD DDRD
#define MOT1BD DDRD
#define MOT2AD DDRD
#define MOT2BD DDRB
#define MOT1END DDRB
#define MOT2END DDRB


#define MOT1AP PORTD
#define MOT1BP PORTD
#define MOT2AP PORTD
#define MOT2BP PORTB
#define MOT1ENP PORTB
#define MOT2ENP PORTB

#define MOT1B (1<<PD5)
#define MOT1A (1<<PD6)
#define MOT2A (1<<PD7)
#define MOT2B (1<<PB0)
#define MOT1EN (1<<PB1)
#define MOT2EN (1<<PB2)


void initMotors();


void setMotorsAB(unsigned char m1a, unsigned char m1b,unsigned char m2a, unsigned char m2b);
void setMotors(int m1, int m2);

void enableMotors(unsigned char m1, unsigned char m2);

void forward();
void backward();
void left();
void right();
void stop();


#endif /* MOTORH_H_ */
