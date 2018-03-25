/*
 * RobotBaseSketch.ino
 *
 * Created: 4/11/2017 8:36:21 PM
 * Author: Sundin
 */ 
#include "Arduino.h"
#include "ADXL335.h"

float x, y;

void setup()
{
	Serial.begin(115200);
	  /* add setup code here, setup code runs once when the processor starts */

}

void loop()
{
	x = 8.0;  //11 clock cycles
	y = 2.5;  //12 clock cycles
	//fixed point
	unsigned long t1 = 0, t2 = 0;
	float res = 0.0;
	for(int i = 0; i<10; i++)
	{
		t1 = micros();
		res = atan2(x,y);
		t2 = micros();
		Serial.print("Res: ");
		Serial.print(res);
		Serial.print(" t= ");
		Serial.println(t2-t1);
		delay(100);
	}
	  /* add main program code here, this code starts again each time it ends */

}



