// FixedPointArithmetic.h

#ifndef _FIXEDPOINTARITHMETIC_h
#define _FIXEDPOINTARITHMETIC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class FixedPointArithmetic 
{
	public:
		static uint32_t MULTI(uint32_t x, uint32_t y);
		static uint32_t DIV(uint32_t numerator, uint32_t denominator);
	private:
		FixedPointArithmetic(){};
		static const uint32_t	resolution;
		static const int		resolutionShift;
		static const float		inversedResolution;
		static const uint16_t	roundBit;
};

#endif

