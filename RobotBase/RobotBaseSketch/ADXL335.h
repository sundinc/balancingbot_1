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
	public:
		double get_x();
		double get_y();
		double get_z();
		int get_x_raw();
		int get_y_raw();
		int get_z_raw();
		int selfTest();
		void setup();
		ADXL335(char x_pin, char y_pin, char z_pin, int resolution);
		ADXL335(char x_pin, char y_pin, char z_pin);
		ADXL335(char x_pin, char y_pin, char z_pin, char st_pin);
	private:
		int get_pin(char pin);
		char X_PIN = -1;
		char Y_PIN = -1;
		char Z_PIN = -1;
		char ST_PIN = -1;
		int RESOLUTION = -1;
		double rawToG(int measured);
};

#endif