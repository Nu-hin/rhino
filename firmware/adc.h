#ifndef ADC_H_
#define ADC_H_

#include "common.h"
#include <avr/io.h>

#define ADC0 0
#define ADC1 1
#define ADC2 2


void initAdc();
int getResult(int adcPort);


#endif /* ADC_H_ */
