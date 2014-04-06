#include "adc.h"

void initAdc()
{
	ADCSRA=(  (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) |(1<<ADPS2));
}

int getResult(int adc)
{
	ADCSRA |=(1<<ADSC);
	ADMUX = adc;
	while ( (ADCSRA & (1<<ADSC)) == (1<<ADSC));
	return ADCW;
}
