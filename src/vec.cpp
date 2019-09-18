#include "main.hpp"

const float vecLength(const vec a)
{
	return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

const vec normalize(const vec a)
{
	float denominator{vecLength(a)};
	if(denominator == 0)
	{
		return a;
	}
	return {a[0] / denominator, a[1] / denominator, a[2] / denominator};
}

const vec stlToVec(const float* stlVec)
{
	return {*stlVec, *(stlVec + 1), *(stlVec + 2)};
}

const vec vecPlus(const vec a, const vec b)
{
	return {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
}

const vec vecMinus(const vec a, const vec b)
{
	return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}

const vec vecTimes(const float a, const vec b)
{
	return {a * b[0], a * b[1], a * b[2]};
}

const float scalarProduct(const vec a, const vec b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
