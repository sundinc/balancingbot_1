/*
 * sensorAccGyro.h
 * This is to use the Analog Devices ADXL335 accelerometer and IDG500 combo board.
 * The ADXL335 measures in g:s and Arduino reads a value between 0 and 1023.
 * The IDG500 measures in DEG/s
 *
 * Input power = 5V
 *	
 * Created: 4/11/2017 8:36:21 PM
 * Author: Sundin
 */ 
#ifndef _sensorAccGyr_H
#define _sensorAccGyr_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "fixmath.h"

class sensorAccGyro
{
	private:
		//For filtering
		uint16_t prev_x, prev_y, prev_z;
		//All pins
		uint8_t xAccPin;
		uint8_t yAccPin;
		uint8_t zAccPin;
		uint8_t xGyrPin;
		uint8_t yGyrPin;
		uint8_t sensorSupplyPin;
		uint8_t sensorGNDPin;
		bool GyroRes;
		//Read the inputs
		uint16_t xRaw();
		uint16_t yRaw();
		uint16_t zRaw();
		uint16_t xGyrRaw();
		uint16_t yGyrRaw();
		Fix16 xCalcAng, zCalcAng;
	public:
		//Input the pins used as sensor inputs and power
		sensorAccGyro(	uint8_t x_Acc_pin, uint8_t y_Acc_pin, uint8_t z_Acc_pin,
						uint8_t x_Gyr_pin, uint8_t y_Gyr_pin, uint8_t sensorSupply_Pin,
						uint8_t sensorGND_Pin, bool Gyro_45_Res = true);
		void Setup();
		
		Fix16 angle();	
};

#endif