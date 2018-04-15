#include "Fuzzy_VNH5019_Single.h"


#define INA_PIN 2
#define INB_PIN 4 
#define PWM_PIN 9

Fuzzy_VNH5019_Motor motor1(INA_PIN, INB_PIN, PWM_PIN);

void setup()
{
	Serial.begin(115200);
	motor1.begin();
	
	spinTest();
}

void loop()
{

	
}

void spinTest()
{
	//This function spins-up and spins-down the motor gradually, in both directions.
	for (int16_t speed = 0; speed < 256; speed++)
	{
		motor1.setSpeed(speed);
		delay(10);
	}
	delay(1000);
	for (int16_t speed = 255; speed > -1; speed--)
	{
		motor1.setSpeed(speed);
		delay(10);
	}
	delay(1000);

	for (int16_t speed = 0; speed > -256; speed--)
	{
		motor1.setSpeed(speed);
		delay(10);
	}
	delay(1000);
	for (int16_t speed = -255; speed < 1; speed++)
	{
		motor1.setSpeed(speed);
		delay(10);
	}
	delay(1000);

}