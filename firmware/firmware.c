#include "common.h"
#include <avr/io.h>
#include <util/delay.h>
#include "shift.h"
#include "sound.h"
#include "adc.h"
#include "ping.h"
#include "motor.h"
#include "usart.h"

void sendReport()
{
	int pot = getResult(ADC1);
	int light = getResult(ADC0);
	unsigned long cm = getDistanceCm();

	uart_putc('R');
	uart_putc(pot);
	uart_putc(pot>>8);


	uart_putc(light);
	uart_putc(light>>8);

	uart_putc(cm);
	uart_putc(cm>>8);
	uart_putc(cm>>16);
	uart_putc(cm>>24);
	uart_putc(0);

}



int main(void)
{
	initShift();
	initSound();
	initMotors();
	initAdc();

	setByte(0xFF);

	uart_init(38400);
	_delay_ms(1000);
	uart_puts("\r\n+STWMOD=0\r\n");
	uart_puts("\r\n+STNA=Rhino2 Drone\r\n");
	uart_puts("\r\n+STAUTO=0\r\n");
	uart_puts("\r\n+STOAUT=1\r\n");
	uart_puts("\r\n +STPIN=0000\r\n");
	_delay_ms(2000);
	uart_puts("\r\n+INQ=1\r\n");
	_delay_ms(2000);


	for(int i=0; i<6; i++)
	{
		beep(100);
		_delay_ms(100);
	}

	setByte(0);

	enableMotors(1,1);
	setMotorsAB(0,0,0,0);

	while(1)
	{
		int z= uart_getc();
		if(z=='Q')
		{
			uart_getc();
			sendReport();
		}

		if(z=='C')
		{
			int lmotor;
			int rmotor;
			setByte(uart_getc());
			z=uart_getc();
			lmotor = z << 8;
			z=uart_getc();
			lmotor |= z;
			z=uart_getc();
			rmotor = z <<8;
			z=uart_getc();
			rmotor |= z;
			z=uart_getc();
			if(z)
			{
				soundOn();
			}
			else
			{
				soundOff();
			}
			uart_getc();

			setMotors(lmotor,rmotor);
		}
	}
}
