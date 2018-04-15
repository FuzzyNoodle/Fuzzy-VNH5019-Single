#include "Fuzzy_VNH5019_Single.h"

Fuzzy_VNH5019_Single motor1(2,4,9);

void setup()
{
	motor1.begin();
	//motor1.setSpeed(255);

}

void loop()
{
	motor1.setDirection(FORWARD);
	spinTest();

	motor1.setDirection(BACKWARD);
	spinTest();
}

void spinTest()
{
	for (uint8_t speed = 0; speed < 255; speed++)
	{
		motor1.setSpeed(speed);
		delay(10);
	}
	delay(1000);
	for (uint8_t speed = 0; speed < 255; speed++)
	{
		motor1.setSpeed(255 - speed);
		delay(10);
	}
	delay(1000);
}