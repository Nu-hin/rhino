#include "motor.h"

void initMotors()
{
	MOT1AD |= MOT1A;
	MOT1BD |= MOT1B;
	MOT2AD |= MOT2A;
	MOT2BD |= MOT2B;
	MOT1END |= MOT1EN;
	MOT2END |= MOT2EN;
}

void setMotorsAB(unsigned char m1a, unsigned char m1b,unsigned char m2a, unsigned char m2b)
{
	if(m1a)
	{
		MOT1AP |= MOT1A;
	}
	else
	{
		MOT1AP &= ~MOT1A;
	}

	if(m1b)
	{
		MOT1BP |= MOT1B;
	}
	else
	{
		MOT1BP &= ~MOT1B;
	}

	if(m2a)
	{
		MOT2AP |= MOT2A;
	}
	else
	{
		MOT2AP &= ~MOT2A;
	}

	if(m2b)
	{
		MOT2BP |= MOT2B;
	}
	else
	{
		MOT2BP &= ~MOT2B;
	}
}

void enableMotors(unsigned char m1, unsigned char m2)
{
	if(m1)
	{
		MOT1ENP |= MOT1EN;
	}
	else
	{
		MOT1ENP &= ~MOT1EN;
	}

	if(m2)
	{
		MOT2ENP |= MOT2EN;
	}
	else
	{
		MOT2ENP &= ~MOT2EN;
	}

}

void forward()
{
	enableMotors(0,0);
	setMotorsAB(1,0,1,0);
	enableMotors(1,1);
}


void backward()
{
	enableMotors(0,0);
	setMotorsAB(0,1,0,1);
	enableMotors(1,1);
}


void left()
{
	enableMotors(0,0);
	setMotorsAB(0,1,1,0);
	enableMotors(1,1);
}
void right()
{
	enableMotors(0,0);
	setMotorsAB(1,0,0,1);
	enableMotors(1,1);
}


void stop()
{
	setMotorsAB(1,1,1,1);
	enableMotors(0,0);
}

void setMotors(int m1, int m2)
{
	setMotorsAB(m1 > 0 ? 1 : 0, m1 < 0 ? 1 : 0, m2 > 0 ? 1 : 0, m2 < 0 ? 1 : 0 );
}
