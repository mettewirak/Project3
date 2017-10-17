#ifndef SOLVER_H
#define SOLVER_H

#include <cmath>
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


	// Constructors and destructer
        solver();
        solver(int iteration_points, double final_time);
        solver(int iteration_points, double final_time, planet Earth);
        ~solver(){}

    // Functions
        void VelocityVerlet(planet Earth, planet Sun);
        void print_to_screen();
        void print_to_file();

};

#endif // SOLVER_H
