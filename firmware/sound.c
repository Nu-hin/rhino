#include "sound.h"


void initSound()
{
	SOUND_PORTD |= SOUND;
	SOUND_PORT |= SOUND;
}

void beep(const int ms)
{
	SOUND_PORT &= ~SOUND;
	delay_ms(ms);
	SOUND_PORT |= SOUND;
}

void soundOn()
{
	SOUND_PORT &= ~SOUND;
}

void soundOff()
{
	SOUND_PORT |= SOUND;
}
