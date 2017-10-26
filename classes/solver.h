#ifndef SOLVER_H
#define SOLVER_H

#include <cmath>
#include <vector>
#include "planet.h"

class solver
{
    public:
    friend class planet;

    // Variables
        double integration_points;
        double time;
        double final_time;
        double dt;
        double G;
        std::vector<planet> all_planets;
        int total_planets;
        double total_kinetic;
        double total_potential;
        double total_mass;
        double center_of_mass[2];
        int dim;


    // Constructors and destructer
        solver();
        solver(int iteration_points, double final_time);
        ~solver(){}

    // Functions
        void VelocityVerlet();                  // Prints the results to file "Resultater.txt"
        void Euler();                           // Prints the results to file "Earth.txt" / other planets
        double force_general(planet& current, planet& other, int dim);
        double force_relativistic(planet& current, planet& other, int dim);
        void print_to_screen();                 // Prints all planets, with their positions and velocities, to screen.
        string get_planet_name(planet current);
        void print_energies();                  // Prints to file file
        void add_planet(planet new_planet);
        void calculate_kinetic_energies();
        void calculate_potential_energies();
        void update_angular_momentum();
        void print_time_spent();                // Prints the time it takes to run VelocityVerlet and Euler to screen.
        void print_to_file(double x,double y,double vx,double vy,std::ofstream *ofile , std::string name);
};

#endif // SOLVER_H
