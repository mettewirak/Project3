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
        double time, final_time;
        double dt;
        double G;
        std::vector<planet> all_planets;
        int total_planets;
        double total_kinetic;
        double total_potential;
        int dim;


    // Constructors and destructer
        solver();
        solver(int iteration_points, double final_time);
        ~solver(){}

    // Functions
        void VelocityVerlet();
        void Euler();
        void print_to_screen();
        string print_planet_name(planet current);
        void print_energies();
        void add_planet(planet new_planet);
        void calculate_kinetic_energies();
        void calculate_potential_energies();
        void update_angular_momentum();
        void print_to_file(planet current);
};

#endif // SOLVER_H
