// 
// 
// 

#include "FixedPointArithmetic.h"
const uint32_t	FixedPointArithmetic::resolution			= 256;	//Resolution
const int		FixedPointArithmetic::resolutionShift		= 8;	// 2^8 = 256;
const float		FixedPointArithmetic::inversedResolution	= (float)(1.0 / double(resolution));
const uint16_t	FixedPointArithmetic::roundBit			= 1 << (resolutionShift-1);

uint32_t FixedPointArithmetic::MULTI(uint32_t x, uint32_t y)
{
	return (x * y + roundBit) >> resolutionShift;
}
uint32_t FixedPointArithmetic::DIV(uint32_t numerator, uint32_t denominator)
{
	uint32_t roundFraction = denominator >> 1;
	return ((numerator << resolutionShift) + roundFraction) / denominator;
}