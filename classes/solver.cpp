#include "solver.h"
#include <iostream>
#include <fstream>
#include <cmath>

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


void solver::VelocityVerlet(planet Earth, planet Sun){

    /*double position[1000][2];
    double velocity[1000][2];
    double acceleration[1000][2];

    double dt = this->final_time/this->integration_points;
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
    cout << "Position: " << endl;
    for(int i=0; i<1000; i++){
        for(int j=0; j<2; j++){
            //cout << this->position[i][j] << "\t";
        }
        cout << endl;
    }
}

void solver::print_to_file(){
/*    ofile.open("Output_data.txt");
    ofile << "Position: " << endl;
    for(int i=0; i<1000; i++){
        for(int j=0; j<2; j++){
            ofile << this->position[i][j] << "\t";
        }
        ofile << endl;
    }
    ofile.close();*/
}
