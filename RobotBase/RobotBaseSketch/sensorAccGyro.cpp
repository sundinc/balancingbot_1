#include "sensorAccGyro.h"

//Input the pins used as sensor inputs and power
sensorAccGyro::sensorAccGyro(	uint8_t x_Acc_pin, uint8_t y_Acc_pin, uint8_t z_Acc_pin,
								uint8_t x_Gyr_pin, uint8_t y_Gyr_pin, uint8_t sensorSupply_Pin,
								uint8_t sensorGND_Pin, bool Gyro_45_Res)
						{
							xAccPin = x_Acc_pin;
							yAccPin = y_Acc_pin;
							zAccPin = z_Acc_pin;
							xGyrPin = x_Gyr_pin;
							yGyrPin = y_Gyr_pin;
							sensorSupplyPin = sensorSupply_Pin;
							sensorGNDPin = sensorGND_Pin;
							GyroRes = Gyro_45_Res;
						}
void sensorAccGyro::Setup()
{
	//5 V reference. 
	analogReference(INTERNAL);
	pinMode(sensorSupplyPin, OUTPUT);
	pinMode(sensorGNDPin, OUTPUT);
	digitalWrite(sensorGNDPin, LOW);
	digitalWrite(sensorSupplyPin, HIGH);
	//Gyro resolution is *4.5
	if(GyroRes)
	{
		
	}
}
uint16_t sensorAccGyro::xRaw()
{
	return analogRead(xAccPin);
}
uint16_t sensorAccGyro::yRaw()
{
	return analogRead(yAccPin);
}
uint16_t sensorAccGyro::zRaw()
{ 
	return analogRead(zAccPin);
}
uint16_t sensorAccGyro::xGyrRaw()
{
	return analogRead(xGyrPin);
}
uint16_t sensorAccGyro::yGyrRaw()
{
	return analogRead(yGyrPin);
}
Fix16 sensorAccGyro::angle()
{
	xCalcAng = fix16_from_int(-xRaw());
	zCalcAng = fix16_from_int(zRaw());
	return atan2(xCalcAng,zCalcAng);
}
