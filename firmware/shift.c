#include "shift.h"


void setByte(const unsigned char a)
{
	SHIFT_REGISTER = a;

	SHIFT_PORT &=~(SHIFT_DATA | SHIFT_CLOCK | SHIFT_LATCH);
	int i;

	for(i=7; i>=0; i--)
	{
		if(SHIFT_REGISTER & (1<<i))
		{
			SHIFT_PORT|=SHIFT_DATA;
		}
		else
		{
			SHIFT_PORT&=~SHIFT_DATA;
		}

		SHIFT_PORT|=SHIFT_CLOCK;
		SHIFT_PORT&=~SHIFT_CLOCK;
	}

	SHIFT_PORT |= SHIFT_LATCH;
}

void initShift()
{
	SHIFT_PORTD |=SHIFT_CLOCK | SHIFT_DATA | SHIFT_LATCH;
	SHIFT_PORT &= ~(SHIFT_CLOCK | SHIFT_DATA | SHIFT_LATCH);
	setByte(0x00);
}
