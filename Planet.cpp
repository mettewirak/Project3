#include "Planet.h"
#include <iostream>

using namespace std;

Planet::Planet(){
	Planet::mass = 0.0;
	Planet::position[0] = 0.0;
	Planet::position[1] = 0.0;
	Planet::velocity[0] = 0.0;
	Planet::velocity[1] = 0.0;
};

Planet::Planet(double m, double x, double y, double vx, double vy)
{
	Planet::mass = m;
	Planet::position[0] = x;
	Planet::position[1] = y;
	Planet::velocity[0] = vx;
	Planet::velocity[1] = vy;
}

Planet::~Planet(){


};
