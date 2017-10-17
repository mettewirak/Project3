#include "Verlet.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
//std::ofstream ofile;

Verlet::Verlet(){

    this->integration_points = 1000;
    this->final_time = 3.0;
    this->mass_Sun = 1;
    this->G = 4*M_PI*M_PI;

    for(int i=0; i<integration_points; i++){
        for(int j=0; j<2; j++){
            this->position[i][j] = 0.0;
            this->velocity[i][j] = 0.0;
            this->acceleration[i][j] = 0.0;
        }
    }
}

Verlet::Verlet(int integration_points, double final_time){

    this->integration_points = integration_points;
    this->final_time = final_time;
    this->mass_Sun = 1;
    this->G = 4*M_PI*M_PI;

    for(int i=0; i<integration_points; i++){
        for(int j=0; j<2; j++){
            this->position[i][j] = 0.0;
            this->velocity[i][j] = 0.0;
            this->acceleration[i][j] = 0.0;
        }
    }
}

double Verlet::distance(double x, double y){

    return sqrt(x*x + y*y);
}


void Verlet::solve(Planet earth){

    double dt = this->final_time/this->integration_points;
    double radius;

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
    }
}

void Verlet::print_to_screen(){
    cout << "Position: " << endl;
    for(int i=0; i<1000; i++){
        for(int j=0; j<2; j++){
            cout << this->position[i][j] << "\t";
        }
        cout << endl;
    }
}

void Verlet::print_to_file(){
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
