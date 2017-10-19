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
        double dim;
        std::vector<planet> all_planets;
        int total_planets;
        double total_kinetic;
        double total_potential;

    // Constructors and destructer
        solver();
        solver(int iteration_points, double final_time);
        ~solver(){}

    // Functions
        void VelocityVerlet();
        void Euler();
        void print_to_screen();
        void print_planet_name(planet current);
        void print_energies();
        void add_planet(planet new_planet);
        void calculate_kinetic_energies();
        void calculate_potential_energies();
        void update_angular_momentum();
};

#endif // SOLVER_H
