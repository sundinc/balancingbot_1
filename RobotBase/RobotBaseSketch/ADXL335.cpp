#include "ADXL335.h"
ADXL335::ADXL335(char x_pin, char y_pin, char z_pin, int resolution) {
	X_PIN = x_pin;
	Y_PIN = y_pin;
	Z_PIN = z_pin;
	ST_PIN = -1;
	RESOLUTION = resolution;
}
ADXL335::ADXL335(char x_pin, char y_pin, char z_pin) {
	X_PIN = x_pin;
	Y_PIN = y_pin;
	Z_PIN = z_pin;
	ST_PIN = -1;
	RESOLUTION = 12;
}
ADXL335::ADXL335(char x_pin, char y_pin, char z_pin, char st_pin) {
	X_PIN = x_pin;
	Y_PIN = y_pin;
	Z_PIN = z_pin;
	ST_PIN = st_pin;
	RESOLUTION = 12;
}
int ADXL335::get_x_raw(){
	return get_pin(X_PIN);
}
int ADXL335::get_y_raw(){
	return get_pin(Y_PIN);
}
int ADXL335::get_z_raw(){
	return get_pin(Z_PIN);
}
int ADXL335::get_pin(char pin) {
	return analogRead(pin);
}
double ADXL335::rawToG(int measured) {
	return (5000.0 / 1023.0/300.0)*(double)measured;
}
double ADXL335::get_x() {
	return rawToG(get_x_raw());
}
double ADXL335::get_y() {
	return rawToG(get_y_raw());
}
double ADXL335::get_z() {
	return rawToG(get_z_raw());
}
int ADXL335::selfTest() {
	/*ToDo: Write the self test routine*/
}
void ADXL335::setup() {
	/*ToDo: Is a setup needed?*/
}