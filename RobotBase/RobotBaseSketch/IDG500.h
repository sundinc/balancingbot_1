/*
* IDG500.h
* This is to use the Analog Devices IDG500 gyro
* The IDG500 measures in DEG/s
* Input power = 5V
*
* Created: 4/11/2017 8:36:21 PM
* Author: Sundin
*/
#ifndef _IDG500_H
#define _IDG500_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class IDG500
{
public:
	IDG500(char x_pin, char y_pin, int resolution);
	IDG500(char x_pin, char y_pin);
	IDG500(char x_pin, char y_pin, char x_45_pin, char y_45_pin);
	double get_x();
	double get_y();
	int get_x_raw();
	int get_y_raw();
	double rawToDeg(int measured);
	enum STATE :int {
		LOW,
		HIGH
	};
	void setResolution(STATE res);

private:
	int RESOLUTION = -1;
	int state = 0;
	char X_PIN;
	char Y_PIN;
	char X_45_PIN;
	char Y_45_PIN;
};

#endif