#include "fdf.h"

float   max(float x, float y)
{
	return ((x > y) ? x : y);
}

float   mod(float x)
{
	return (x < 0) ? -x : x;
}