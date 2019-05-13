#include "Rand.h"
mt19937 Rand::t;
uniform_real_distribution<double> Rand::d;

int Rand::getRand(int min, int max)
{
        return ((int)getRand((double)min, (double)max));
}

float Rand::getRand(float min, float max)
{
	return ((float)getRand((double)min, (double)max));
}

double Rand::getRand(double min, double max)
{
	return min + d(t) * (max - min);
}

void Rand::initialize()
{
	t = mt19937(time(0));
	d = uniform_real_distribution<double> (0, 1);
}
