/*
 * ADXL335.h
 * This is to use the Analog Devices ADXL335 accelerometer
 * The ADXL335 measures in g:s 
 * Input power = 5V
 *	
 * Created: 4/11/2017 8:36:21 PM
 * Author: Sundin
 */ 
#ifndef _ADXL335_H
#define _ADXL335_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class ADXL335
{
	private:
		int get_x_raw();
		int get_y_raw();
		int get_z_raw();
		int get_pin(char pin);
		char X_PIN = 0;
		char Y_PIN = 0;
		char Z_PIN = 0;
		double resolution = 0;
		double rawToG(int measured);

	public:
		enum RES {
			10_bit = 10,
			12_bit = 12,
			16_bit = 16
		};
		ADXL335(char x_pin, char y_pin char z_pin, enum RES);
		double get_x();
		double get_y();
		double get_z();

};

#endif