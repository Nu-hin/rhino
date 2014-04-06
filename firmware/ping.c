#include "ping.h"
#include "shift.h"



unsigned long pulseIn(unsigned long timeout)
{
	unsigned long width = 0; // keep initialization out of time critical area
	unsigned long numloops = 0;
	unsigned long maxloops = microsecondsToClockCycles(timeout) / 16;
	while ((PINGIN & PINGPIN))
	if (numloops++ == maxloops)
	return 0;



	// wait for the pulse to start
	while (!(PINGIN & PINGPIN))
	if (numloops++ == maxloops)
	return 0;


	// wait for the pulse to stop
	while ((PINGIN & PINGPIN)) {
		if (numloops++ == maxloops)
		return 0;
		width++;
	}


	// convert the reading to microseconds. The loop has been determined
	// to be 20 clock cycles long and have about 16 clocks between the edge
	// and the start of the loop. There will be some error introduced by
	// the interrupt handlers.
	return clockCyclesToMicroseconds(width * 21 + 16);
}

unsigned long getDistanceCm()
{
	  PINGD |= PINGPIN;

	  PINGP &= (~PINGPIN);
	  _delay_us(10);
	  PINGP |= PINGPIN;
	  _delay_us(15);
	  PINGP &= (~PINGPIN);
	  _delay_us(20);


	  PINGD &= (~PINGPIN);

	  unsigned long duration = pulseIn(100000L);
	  return USTOCM(duration);
}
