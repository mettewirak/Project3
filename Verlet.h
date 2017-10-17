#ifndef VERLET_H
#define VERLET_H

#include <cmath>
#include "Planet.h"

class Verlet
{
    private:

    protected:

    public:
    // Variables
        double integration_points;
        double final_time;
        // double dt;
        double mass_Sun;
        double G;

        double position[1000][2];
        double velocity[1000][2];
        double acceleration[1000][2];


    // Constructors and destructer
        Verlet();
        Verlet(int iteration_points, double final_time);
        Verlet(int iteration_points, double final_time, Planet Earth);
        ~Verlet(){}

        friend class Planet;
    // Functions
        void solve(Planet earth);
        double distance(double x, double y);
        void print_to_screen();
        void print_to_file();

};

#endif // VERLET_H
