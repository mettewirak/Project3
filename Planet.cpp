#include "Planet.h"
#include <iostream>
#include <cmath>

using namespace std;

Planet::Planet(){

    this->mass = 1;
    for(int i=0; i<2; i++){
        this->position[i] = 0.0;
        this->velocity[i] = 0.0;
        this->acceleration[i] = 0.0;
    }
}

Planet::Planet(double m, double pos_x, double pos_y, double vel_x, double vel_y, double acc_x, double acc_y)
{
    this->mass = m;
    this->position[0] = pos_x;
    this->position[1] = pos_y;
    this->velocity[0] = vel_x;
    this->velocity[1] = vel_y;
    this->acceleration[0] = acc_x;
    this->acceleration[1] = acc_y;
}

Planet::~Planet(){


}

double Planet::radius_to_sun(double position[2]){

    double temp = 0.0;
    for(int i=0; i<2; i++){
        temp = temp + position[i]*position[i];
    }

    return sqrt(temp);
}

void Planet::print_to_screen(){

    cout << "The mass of the planet is " << this->mass << "." << endl;
    cout << "The planet has coordinates " << this->position[0] << ", " << this-> position[1] << "." << endl;
    cout << "The planet has velocity " << this->velocity[0] << ", " << this->velocity[1] << "." << endl;
    cout << "The planet has acceleration " << this->acceleration[0] << ", " << this->acceleration[1] << "." << endl;
}
