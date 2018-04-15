/*
 Name:		Fuzzy_VNH5019_Single.h
 Created:	4/15/2018 7:25:47 PM
 Author:	georgychen
 Editor:	http://www.visualmicro.com
*/

#ifndef _Fuzzy_VNH5019_Single_h
#define _Fuzzy_VNH5019_Single_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum MOTOR_DIRECTION
{
	FORWARD,
	BACKWARD,
};

class Fuzzy_VNH5019_Single
{
	public:
		Fuzzy_VNH5019_Single(uint8_t INA_PIN, uint8_t INB_PIN, uint8_t PWM_PIN);  //Constructor with required pin selection.
		void begin();
		void setSpeed(uint8_t speed); //Speed range from 0 to 255, while 0 is stopped, 255 is full speed.
		void setDirection(MOTOR_DIRECTION direction);
	private:
		uint8_t _INA;
		uint8_t _INB;
		uint8_t _PWM;
		uint8_t _speed;
};
#endif

