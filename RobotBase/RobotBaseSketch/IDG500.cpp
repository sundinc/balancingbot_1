#include "IDG500.h"
IDG500::IDG500(char x_pin, char y_pin, int adc_resolution) {
	X_PIN = x_pin;
	Y_PIN = y_pin;
	ADC_RESOLUTION = adc_resolution;
}
IDG500::IDG500(char x_pin, char y_pin) {
	X_PIN = x_pin;
	Y_PIN = y_pin;
	ADC_RESOLUTION = 12; /*FIX THIS!! In some way the nr of bits must be translated to a number 12 bits = 1023*/
}
IDG500::IDG500(char x_pin, char y_pin, char x_45_pin, char y_45_pin) {
	X_PIN = x_pin;
	Y_PIN = y_pin;
	ADC_RESOLUTION = 12;
	X_45_PIN = x_45_pin;
	Y_45_PIN = y_45_pin;
}
double IDG500::get_x() {
	return rawToDeg(get_x_raw());
}
double IDG500::get_y() {
	return rawToDeg(get_y_raw());
}
int IDG500::get_x_raw() {
	if (RESOLUTION == STATE.Low)
		analogRead(X_PIN);
	else
		analogRead(X_45_PIN);
}
int IDG500::get_y_raw() {
	if (RESOLUTION == STATE.Low)
		analogRead(Y_PIN);
	else
		analogRead(Y_45_PIN);
}
double IDG500::rawToDeg(int measured) {
	if (RESOLUTION == STATE.Low) {
		return (5000.0 / 1023 / 2.0)(double)measured;
	}
	else {
		return (5000.0 / 1023 / 9.1)(double)measured;
	}
}
void IDG500::setResolution(STATE res) {
	RESOLUTION = res;
}