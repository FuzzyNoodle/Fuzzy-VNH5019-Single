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
	NORMAL_DIRECTION = 0, //default value
	REVERSED_DIRECTION,
};

class Fuzzy_VNH5019_Motor
{
	public:
		Fuzzy_VNH5019_Motor(uint8_t INA_PIN, uint8_t INB_PIN, uint8_t PWM_PIN);  //Constructor with required pin selection.
		void begin();
		void setSpeed(int16_t speed); //Speed range from -255 to 255, while 0 is coast, +/- 255 is full speed.
		void setDirection(MOTOR_DIRECTION direction); //
		MOTOR_DIRECTION getDirection();
	private:
		uint8_t _INA;
		uint8_t _INB;
		uint8_t _PWM;
		uint8_t _speed;
		MOTOR_DIRECTION _motorDirection;
};
#endif

