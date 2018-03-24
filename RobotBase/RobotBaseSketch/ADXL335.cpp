#include "ADXL335.h"
int ADXL335::get_x_raw();
int ADXL335::get_y_raw();
int ADXL335::get_z_raw();
int ADXL335::get_pin(char pin);
char ADXL335::X_PIN = 0;
char ADXL335::Y_PIN = 0;
char ADXL335::Z_PIN = 0;
double ADXL335::resolution = 0;
double ADXL335::rawToG(int measured);
ADXL335::ADXL335(char x_pin, char y_pin char z_pin, enum RES);
		double ADXL335::get_x();
		double ADXL335::get_y();
		double ADXL335::get_z();