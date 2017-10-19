#include "planet.h"
#include <iostream>
#include <cmath>

using namespace std;

planet::planet(){

    mass = 1;
    for(int i=0; i<2; i++){
        position[i] = 0.0;
        velocity[i] = 0.0;
    }
    potential = 0;
    kinetic = 0;
    angular_momentum = find_angular_momentum();
}


planet::planet(double m, double distance){
    mass = m;
    position[0] = distance;
    position[1] = 0.0;
    velocity[0] = 0.0;
    if(distance==0)
        {velocity[1] = 0.0;}
    else
        {velocity[1] = 2*M_PI/sqrt(distance);}
    potential = 0.0;
    kinetic = 0.0;
    angular_momentum = find_angular_momentum();
}


planet::planet(double m, double pos_x, double pos_y, double vel_x, double vel_y){

    mass = m;
    position[0] = pos_x;
    position[1] = pos_y;
    velocity[0] = vel_x;
    velocity[1] = vel_y;
    kinetic = 0.0;
    potential = 0.0;
    angular_momentum = find_angular_momentum();
}


planet::~planet(){

}


double planet::distance(planet otherPlanet){

    double xx = pow(this->position[0]-otherPlanet.position[0], 2.0);
    double yy = pow(this->position[1]-otherPlanet.position[1], 2.0);

    return sqrt(xx + yy);
}


void planet::print_to_screen(){

    cout << "The mass of the planet is " << mass << "." << endl;
    cout << "The planet has coordinates " << position[0] << ", " << position[1] << "." << endl;
    cout << "The planet has velocity " << velocity[0] << ", " << velocity[1] << "." << endl;
}


double planet::kinetic_energy(){

    return 0.5*this->mass*(this->velocity[0]*this->velocity[0]+this->velocity[1]*this->velocity[1]);
}


double planet::find_angular_momentum(){

    return mass*(position[0]*velocity[1] - position[1]*velocity[0]);
}
