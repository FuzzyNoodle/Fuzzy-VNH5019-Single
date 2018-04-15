/*
 Name:		Fuzzy_VNH5019_Single.cpp
 Created:	4/15/2018 7:25:47 PM
 Author:	georgychen
 Editor:	http://www.visualmicro.com
*/

#include "Fuzzy_VNH5019_Single.h"

Fuzzy_VNH5019_Single::Fuzzy_VNH5019_Single(uint8_t INA_PIN, uint8_t INB_PIN, uint8_t PWM_PIN)
{
	_INA = INA_PIN;
	_INB = INB_PIN;
	_PWM = PWM_PIN;
}

void Fuzzy_VNH5019_Single::begin()
{
	pinMode(_INA, OUTPUT);
	pinMode(_INB, OUTPUT);
	pinMode(_PWM, OUTPUT);

	digitalWrite(_INA, LOW);
	digitalWrite(_INB, LOW);


}

void Fuzzy_VNH5019_Single::setSpeed(uint8_t speed)
{
	analogWrite(_PWM, speed);
}

void Fuzzy_VNH5019_Single::setDirection(MOTOR_DIRECTION direction)
{
	if (direction == FORWARD)
	{
		digitalWrite(_INA, HIGH);
		digitalWrite(_INB, LOW);
	}
	else if (direction == BACKWARD)
	{
		digitalWrite(_INA, LOW);
		digitalWrite(_INB, HIGH);
	}
}
