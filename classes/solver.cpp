#include "solver.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

solver::solver(){

    integration_points = 100000;
    time = 0.0;
    final_time = 100;
    dt = final_time/integration_points;
    G = 4*M_PI*M_PI;
    dim = 2;
    total_planets = 0;
    dim =2;
}


solver::solver(int integration_points, double final_time){

    this->integration_points = integration_points;
    time = 0.0;
    this->final_time = final_time;
    dt = final_time/integration_points;
    G = 4*M_PI*M_PI;
    dim = 2;
    total_planets = 0;
}


void solver::VelocityVerlet(){

    std::ofstream vofile("Resultater.txt");
    cout<<"her";

    // Lager et sted å lagre akselerasjonene.
    double **acceleration, **acceleration_new;
    acceleration = new double*[total_planets];
    acceleration_new = new double*[total_planets];
    //Finner summen momentum til planetene
    double total_momentum_x;
    double total_momentum_y;
    for(int nr1=1; nr1<total_planets; nr1++){ // !!! Antar at Sola alltid er planet nr. 0.
        planet &current= all_planets[nr1];
        total_momentum_x=total_momentum_x+current.velocity[0]*current.mass;
        total_momentum_y=total_momentum_y+current.velocity[1]*current.mass;
    }
    planet &current= all_planets[0];
    current.velocity[0]=-total_momentum_x;
    current.velocity[1]=-total_momentum_y;


    cout<<total_momentum_x/365.242199<<"y "<<total_momentum_y/365.242199<<endl;
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
        for(int nr1=0; nr1<total_planets; nr1++){ // !!! Antar at Sola alltid er planet nr. 0.
            planet &current= all_planets[nr1];
            std::string name= get_planet_name(current);
            // Itererer gjennom alle andre planeter for å finne krefter på planet nr 1.
            for(int nr2=0; nr2<total_planets; nr2++){

                planet &other = all_planets[nr2];

                if(nr1!=nr2){

                    force[0] += force_relativistic(current, other, 0); // 7 FLOPS * (total_planets - 1)
                    force[1] += force_relativistic(current, other, 1); // 7 FLOPS * (total_planets - 1)
                }
            }

            for(int dim=0; dim<2; dim++){

                // Finne akselerasjon
                acceleration[nr1][dim] = force[dim]/current.mass; // 1 FLOP

                // Regne ut current posisjon
                current.position[dim] += dt*current.velocity[dim]+((dt*dt)/2)*acceleration[nr1][dim];
            }

            // Gjør hele kraft-biten en gang til for å finne a(t+dt)
            for(int nr2=0; nr2<total_planets; nr2++){

                planet &other = all_planets[nr2];

                if(nr1!=nr2){

                    force_new[0] += force_relativistic(current, other, 0); // 7 FLOPS * (total_planets - 1)
                    force_new[1] += force_relativistic(current, other, 1); // 7 FLOPS * * (total_planets - 1)
                }
            }

            for(int dim = 0; dim<2; dim++){
                // Finne akselerasjon_dt
                acceleration_new[nr1][dim] = force_new[dim]/current.mass;

                //Regne ut current fart
                current.velocity[dim] += (dt/2)*(acceleration[nr1][dim] + acceleration_new[nr1][dim]);
            }

            print_to_file(current.position[0], current.position[1], current.velocity[0], current.velocity[1], &vofile, name);

            //output_file << setw(12) << current.position[0] << " " << setw(12) << current.position[1] << " " << setw(12) << current.velocity[0] << "" << setw(12) << current.velocity[1] << " ";

            force[0] = force[1] = 0.0;
            force_new[0] = force_new[1] = 0.0;
        }

        time += dt;
        //output_file << endl;
    }

    // Delete matrices
    for(int i=0; i<total_planets; i++){
        delete [] acceleration[i];
        delete [] acceleration_new[i];
    }
    delete [] acceleration;
    delete [] acceleration_new;

    vofile.close();
}


void solver::Euler(){
    using namespace std;
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

    double r_js=1;

std::ofstream eofile;
eofile.open("Euler_forward_Sun_Earth.txt");

    for (int nr1=1; nr1<total_planets; nr1++){

        planet &current= all_planets[nr1];
        string name= get_planet_name(current);
        //string filename=name +".txt";




    for (int j=1; j<integration_points; j++){
            r_js = sqrt(current.position[0]*current.position[0]+current.position[1]*current.position[1]);
    for(int i=0; i<dim; i++) {
        acceleration[nr1][i] = -G*current.position[i]/(r_js*r_js*r_js);

        current.position[i] = current.position[i]+dt*current.velocity[i];
        current.velocity[i] = current.velocity[i]+ dt*acceleration[nr1][i];





    }

    //cout<< "x= "<< current.position[0]<<endl;

   print_to_file(current.position[0], current.position[1], current.velocity[0], current.velocity[1], &eofile, name );

    }
       }
eofile.close();
}


double solver::force_general(planet current, planet other, int dim){

    return ((G*current.mass*other.mass*(other.position[dim] - current.position[dim]))/pow((current.distance(other)),3));
}


double solver::force_relativistic(planet current, planet other, int dim){

    double general = (G*current.mass*other.mass)/pow(current.distance(other),2);
    double l = current.position[0]*current.velocity[1] - current.position[1]*current.velocity[0];
    double r = current.distance(other);
    double c = 63241.0; // In AU/years. Value can be double checked.

    double dekomponering = (other.position[dim] - current.position[dim])/r;

    return (general*(1 + (3*l*l)/(r*r*c*c)))*dekomponering;
}


void solver::print_to_screen(){

    // Printing mass, position and velocity of all planets
    for(int i=0; i<total_planets; i++){
        planet &current = this->all_planets[i];

        get_planet_name(current);
        cout << endl;
        cout << "Mass: " << current.mass << "\n";
        cout << "Position: (" << current.position[0] << ", " << current.position[1] << ")\n";
        cout << "Velocity: (" << current.velocity[0] << ", " << current.velocity[1] << ")\n\n";
    }
}


string solver::get_planet_name(planet current){

    // Skriv ut navnet på planeten
    if(current.mass==1){ return "Sun";}
    else if(current.mass==1.65e-7){ return "Mercury";}
    else if(current.mass==2.45e-6){return "Venus";}
    else if(current.mass==3e-6){return "Earth";}
    else if(current.mass==3.3e-7){return "Mars";}
    else if(current.mass==9.5e-4){return "Jupiter";}
    else if(current.mass==2.75e-4){return "Saturn";}
    else if(current.mass==4.4e-5){return "Uranus";}
    else if(current.mass==5.15e-5){return "Neptune";}
    else if(current.mass==6.55e-9){return "Pluto";}


}


void solver::print_to_file(double x,double y,double vx,double vy,std::ofstream *ofile , std::string name){

    *ofile<<"planet= " <<name<<  " x= "<<x<<" y= "<<y<<" vx= "<<vx<<" vy= "<<vy<<endl;


}



void solver::add_planet(planet new_planet){

    // Legger til en ny planet bakerst i vektoren.
    total_planets+=1;
    all_planets.push_back(new_planet);
}


void solver::calculate_kinetic_energies(){ // Bevares bra.
    total_kinetic = 0.0;
    for(int i=0; i<this->total_planets; i++){
        planet &current = this->all_planets[i];
        current.kinetic = current.kinetic_energy();
        total_kinetic += current.kinetic;
    }
}


void solver::calculate_potential_energies(){ // Bevares ikke bra nok. Noe som kan fikses?? Ser på tallene at den dobbles av Velocity Verlet. Merkelig.
    total_potential = 0.0;

    for(int nr1 = 0; nr1<total_planets; nr1++){
        planet &current = all_planets[nr1];

        for(int nr2 = 0; nr2<total_planets; nr2++){
            planet &other = all_planets[nr2];

            if(nr1!=nr2){
                current.potential += (G*current.mass*other.mass)/current.distance(other);
                total_potential += current.potential;
            }
        }
    }
}


void solver::print_energies(){

    std::ofstream output_energies;
    output_energies.open("Resultat_energier.txt");

    // Kinetisk
    output_energies << "Kinetic energies: " << endl;
    calculate_kinetic_energies();
    for(int i=0; i<total_planets; i++){
        planet &current = all_planets[i];
        output_energies << current.kinetic << "\t";
    }
    output_energies << endl;

    VelocityVerlet();
    calculate_kinetic_energies();

    for(int i=0; i<total_planets; i++){
        planet &current = all_planets[i];
        output_energies << current.kinetic << "\t";
    }

    output_energies << endl;
    output_energies.close();
}


void solver::update_angular_momentum(){
    for(int i=0; i<total_planets; i++){
        planet &current = all_planets[i];
        current.angular_momentum = current.find_angular_momentum();
    }
}



void solver::print_time_spent(){

    clock_t start1, start2;
    double duration1, duration2;
    start1 = clock();
    Euler();
    duration1 = (clock() - start1)/double(CLOCKS_PER_SEC);
    cout << "Time spent on Euler: " << duration1 << " seconds" << endl;

    start2 = clock();
    VelocityVerlet();
    duration2 = (clock() - start2)/double(CLOCKS_PER_SEC);
    cout << "Time spent on Velocity Verlet: " << duration2 << " seconds" << endl;
}

