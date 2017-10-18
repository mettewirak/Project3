#include "solver.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

solver::solver(){

    integration_points = 1000;
    time = 0.0;
    final_time = 3.0;
    dt = final_time/integration_points;
    G = 4*M_PI*M_PI;
    total_planets = 0;
}


solver::solver(int integration_points, double final_time){

    this->integration_points = integration_points;
    time = 0.0;
    this->final_time = final_time;
    dt = final_time/integration_points;
    G = 4*M_PI*M_PI;
    total_planets = 0;
}


void solver::VelocityVerlet(){

    std::ofstream output_file("Resultater.txt");

    // Lager et sted å lagre akselerasjonene.
    double **acceleration, **acceleration_new;
    acceleration = new double*[total_planets];
    acceleration_new = new double*[total_planets];
    for(int i=0; i<total_planets; i++){
        acceleration[i] = new double[2]; // Dimension
        acceleration_new[i] = new double[2];
    }

    // Initsialiserer akselerasjonsmatrisene.
    for(int i=0; i<total_planets; i++){
        for(int j=0; j<2; j++){
            acceleration[i][j] = 0.0;
            acceleration_new[i][j] = 0.0;
        }
    }

    // Lagrer kraftvektorene.
    double force[2], force_new[2];
    force[0] = force[1] = force_new[0] = force_new[1] = 0.0;

    time += dt;
    while (time<final_time) {

        // Iterere gjennom alle planetene for å finne posisjon, fart.
        for(int nr1=1; nr1<total_planets; nr1++){ // !!! Antar at Sola alltid er planet nr. 0.

            planet &current = all_planets[nr1];

            // Itererer gjennom alle andre planeter for å finne krefter på planet nr 1.
            for(int nr2=0; nr2<total_planets; nr2++){

                planet &other = all_planets[nr2];

                if(nr1!=nr2){
                    force[0] += (G*current.mass*other.mass*(other.position[0] - current.position[0]))/pow((current.distance(other)),3);
                    force[1] += (G*current.mass*other.mass*(other.position[1] - current.position[1]))/pow((current.distance(other)),3);
                }
            }

            for(int dim=0; dim<2; dim++){

                // Finne akselerasjon
                acceleration[nr1][dim] = force[dim]/current.mass;

                // Regne ut current posisjon
                current.position[dim] += dt*current.velocity[dim]+((dt*dt)/2)*acceleration[nr1][dim];
            }

            // Gjør hele kraft-biten en gang til for å finne a(t+dt)
            for(int nr2=0; nr2<total_planets; nr2++){

                planet &other = all_planets[nr2];

                if(nr1!=nr2){
                    force_new[0] += (G*current.mass*other.mass*(other.position[0] - current.position[0]))/pow((current.distance(other)),3);
                    force_new[1] += (G*current.mass*other.mass*(other.position[1] - current.position[1]))/pow((current.distance(other)),3);
                }
            }

            for(int dim = 0; dim<2; dim++){
                // Finne akselerasjon_dt
                acceleration_new[nr1][dim] = force_new[dim]/current.mass;

                //Regne ut current fart
                current.velocity[dim] += (dt/2)*(acceleration[nr1][dim] + acceleration_new[nr1][dim]);
            }

            output_file << setw(12) << current.position[0] << " " << setw(12) << current.position[1] << " " << setw(12) << current.velocity[0] << "" << setw(12) << current.velocity[1] << " ";

            force[0] = force[1] = 0.0;
            force_new[0] = force_new[1] = 0.0;
        }

        time += dt;
        output_file << endl;
    }

    // Delete matrices
    for(int i=0; i<total_planets; i++){
        delete [] acceleration[i];
        delete [] acceleration_new[i];
    }
    delete [] acceleration;
    delete [] acceleration_new;

    output_file.close();
}


void solver::print_to_screen(){

    // Printing mass, position and velocity of all planets
    for(int i=0; i<total_planets; i++){
        planet &current = this->all_planets[i];

        print_planet_name(current);
        cout << endl;
        cout << "Mass: " << current.mass << "\n";
        cout << "Position: (" << current.position[0] << ", " << current.position[1] << ")\n";
        cout << "Velocity: (" << current.velocity[0] << ", " << current.velocity[1] << ")\n\n";
    }
}


void solver::print_planet_name(planet current){

    // Skriv ut navnet på planeten
    if(current.mass==1){cout << "The sun";}
    else if(current.mass==1.65e-7){cout << "Mercury";}
    else if(current.mass==2.45e-6){cout << "Venus";}
    else if(current.mass==3e-6){cout << "Earth";}
    else if(current.mass==3.3e-7){cout << "Mars";}
    else if(current.mass==9.5e-4){cout << "Jupiter";}
    else if(current.mass==2.75e-4){cout << "Saturn";}
    else if(current.mass==4.4e-5){cout << "Uranus";}
    else if(current.mass==5.15e-5){cout << "Neptune";}
    else if(current.mass==6.55e-9){cout << "Pluto";}
}


void solver::add_planet(planet new_planet){

    // Legger til en ny planet bakerst i vektoren.
    total_planets+=1;
    all_planets.push_back(new_planet);
}


void solver::calculate_kinetic_energies(){
    total_kinetic = 0.0;
    for(int i=0; i<this->total_planets; i++){
        planet &current = this->all_planets[i];
        current.kinetic = current.kinetic_energy();
        total_kinetic += current.kinetic;
    }
}

void solver::print_energies(){
    for(int i=0; i<total_planets; i++){
        planet &current = all_planets[i];
        print_planet_name(current);
        cout << ": " << current.kinetic << endl;
    }
}