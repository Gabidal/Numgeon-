#ifndef _RAND_H_
#define _DAND_H_
#include <time.h>
#include <random>
using namespace std;

class Rand
{
public:
	static void initialize();
	static int getRand(int min, int max);
	static float getRand(float min, float max);
	static double getRand(double min, double max);
private:
	static mt19937 t;
	static uniform_real_distribution<double> d;
};

#endif
