#include <iostream>
#include <math>
#include "classes\Planet.h"
#include "classes\Euler.h"
#include "classes\Verlet.h"
using namespace std;

int main(){ 
	
	double const G = 6.67408 * pow(10, -11);

	// 1. (d position_x/dt) = velocity_x 
	// 2. (d veolcity_x/dt) = G*mass_Sun / r^2 = velocity_x^2/r

	// 3. (d position_y/dt) = velocity_y
	// 4. (d veolcity_y/dt) = G*mass_Sun / r^2 = velocity_y^2/r

	// velocity^2 r = G mass_Sun

	// EULERS FORWARD METHOD
	int N;
	double step_length;

	// f'(x) = (f(x+step_length) - f(x))/step_length + 0(h);

	


	// VELOCITY VERLET METHOD


	return 0;
}