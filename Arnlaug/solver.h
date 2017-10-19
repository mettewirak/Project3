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
        double final_time;
        // double dt;
        double mass_Sun;
        double G;
        std::vector<planet> all_planets;

    // Constructors and destructer
        solver();
        solver(int iteration_points, double final_time);
        ~solver(){}

    // Functions
        void VelocityVerlet();
        void print_to_screen();
        void add_planet(planet new_planet);

};

#endif // SOLVER_H