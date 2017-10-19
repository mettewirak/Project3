#include "solver.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;
//std::ofstream ofile;

solver::solver(){

    this->integration_points = 1000;
    this->final_time = 3.0;
    this->mass_Sun = 1;
    this->G = 4*M_PI*M_PI;
}

solver::solver(int integration_points, double final_time){

    this->integration_points = integration_points;
    this->final_time = final_time;
    this->mass_Sun = 1;
    this->G = 4*M_PI*M_PI;
}


void solver::VelocityVerlet(){
/*
    Lager en matrise med akselerasjonene til de forskjellige vektorene i forskjellige retninger.
    Itererer over tiden, og oppdaterer i hvert steg position og velocity. Kan bruke +=, siden den neste verdien alltid bare er å legge til faktorer.

    */
    double **acceleration;
    *acceleration = new double[this->all_planets.size()];
    for(int i=0; i<this->all_planets-size(); i++){
        acceleration[i] = new double[2]; // Dimension
    }

    for(int i=0; i<this->all_planets.size(); i++){
        for(int j=0; j<2; j++){
            acceleration[i][j] = 0.0;
        }
    }

    double dt = this->final_time/this->integration_points;
    for(double time = 0.0; time<this->final_time; time=time+dt){

        for(int nr1=0; nr1<this->all_planets.size(); nr1++){

            planet &current = all_planets[nr1];

        }



    }




    /*double dt = this->final_time/this->integration_points;
    double radius = Earth.distance(Sun);

    for(int i=0; i<2; i++){
        this->position[0][i] = earth.position[i];
        this->velocity[0][i] = earth.velocity[i];
        this->acceleration[0][i] = earth.velocity[i];
    }

    for(int i=0; i<(integration_points-1); i++){
        radius = distance(this->position[i][0], this->position[i][1]);

        for(int j=0; j<2; j++){
            this->position[i+1][j] = this->position[i][j] + dt*this->velocity[i][j] + ((dt*dt)/2)*this->acceleration[i][j];
            this->acceleration[i+1][j] = -this->G*this->mass_Sun*this->position[i][j]/(radius*radius*radius);
            this->velocity[i+1][j] = this->velocity[i][j] + (dt/2)*(this->acceleration[i+1][j] + this->acceleration[i][j]);
        }
    }*/
}

void solver::print_to_screen(){
    // Printing mass, position and velocity of all planets
    for(int i=0; i<this->all_planets.size(); i++){
        planet &current = this->all_planets[i];
        cout << "Planet " << i << ": \n";
        cout << "Mass: " << current.mass << "\n";
        cout << "Position: (" << current.position[0] << ", " << current.position[1] << ")\n";
        cout << "Velocity: (" << current.velocity[0] << ", " << current.velocity[1] << ")\n\n";
    }
}


void solver::add_planet(planet new_planet){

    // Legger til en ny planet bakerst i vektoren.
    this->all_planets.push_back(new_planet);
}
