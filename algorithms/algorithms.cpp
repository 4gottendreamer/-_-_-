#include <iostream>
#include "algorithms.h"

using namespace alg;

float alg::Q_rsqrt( float _Number )
{
	float x2 = _Number * .5F;
	float y = _Number;
	const float threehalves = 1.5F;

	long i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalves - (x2 * y * y));	// 1st iteration
	y = y * (threehalves - (x2 * y * y));	// 2nd iteration, addition accuracy; can be removed
	return y;
}

// TODO: ДОПИЛИТЬ
double alg::dQ_rsqrt( double _Number )
{
	double x2 = _Number * .5F;
	double y = _Number;
	const double threehalves = 1.5F;

	int64_t i = *(int64_t*)&y;
	i = 0x5f3759dF - (i >> 1);
	y = *(double*)&i;
	y = y * (threehalves - (x2 * y * y));	// 1st iteration
	y = y * (threehalves - (x2 * y * y));	// 2nd iteration, addition accuracy; can be removed
	return y;
}
