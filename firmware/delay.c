#include "delay.h"

void delay_ms(const int ms)
{
	for(int i=0; i<ms; i++)
	{
		_delay_us(1000);
	}
}



