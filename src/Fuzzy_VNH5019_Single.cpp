/*
 Name:		Fuzzy_VNH5019_Single.cpp
 Created:	4/15/2018 7:25:47 PM
 Author:	georgychen
 Editor:	http://www.visualmicro.com
*/

#include "Fuzzy_VNH5019_Single.h"

Fuzzy_VNH5019_Motor::Fuzzy_VNH5019_Motor(uint8_t INA_PIN, uint8_t INB_PIN, uint8_t PWM_PIN)
{
	_INA = INA_PIN;
	_INB = INB_PIN;
	_PWM = PWM_PIN;
	
}

void Fuzzy_VNH5019_Motor::begin()
{
	pinMode(_INA, OUTPUT);
	pinMode(_INB, OUTPUT);
	pinMode(_PWM, OUTPUT);

	digitalWrite(_INA, LOW);
	digitalWrite(_INB, LOW);

	_motorDirection = NORMAL_DIRECTION;
}

void Fuzzy_VNH5019_Motor::setSpeed(int16_t speed)
{
	if (speed > 0)
	{
		if (speed > 255)speed = 255;
		if (_motorDirection == NORMAL_DIRECTION)
		{
			digitalWrite(_INA, HIGH);
			digitalWrite(_INB, LOW);
		}
		else if (_motorDirection == REVERSED_DIRECTION)
		{
			digitalWrite(_INA, LOW);
			digitalWrite(_INB, HIGH);
		}
		analogWrite(_PWM, speed);
	}
	else if(speed < 0)
	{
		if (speed < -255)speed = -255;
		if (_motorDirection == NORMAL_DIRECTION)
		{
			digitalWrite(_INA, LOW);
			digitalWrite(_INB, HIGH);
		}
		else if (_motorDirection == REVERSED_DIRECTION)
		{
			digitalWrite(_INA, HIGH);
			digitalWrite(_INB, LOW);
		}
		analogWrite(_PWM, -speed);
	}
	else //speed =0
	{
		analogWrite(_PWM, speed);
	}
	
}

void Fuzzy_VNH5019_Motor::setDirection(MOTOR_DIRECTION direction)
{
	_motorDirection = direction;
}

MOTOR_DIRECTION Fuzzy_VNH5019_Motor::getDirection()
{
	return _motorDirection;
}
