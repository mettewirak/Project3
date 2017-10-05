#include <iostream>
// #include "Planet.h"
using namespace std;

int main(){ // Aim: compute the motion of th eEarth using different methods for solving ODE's. 
	
	double G, mass_Earth, mass_Sun;
	double velocity_x, velocity_y, position_x, position_y;

	// 1. (d position_x/dt) = velocity_x 
	// 2. (d veolcity_x/dt) = G*mass_Sun / r^2 = velocity_x^2/r

	// 3. (d position_y/dt) = velocity_y
	// 4. (d veolcity_y/dt) = G*mass_Sun / r^2 = velocity_y^2/r

	// velocity^2 r = G mass_Sun

	// EULERS FORWARD METHOD
	int N;
	double step_length = 1 / N;

	// f'(x) = (f(x+step_length) - f(x))/step_length + 0(h);

	


	// VELOCITY VERLET METHOD


	return 0;
}