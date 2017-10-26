#ifndef PLANET_H
#include <string>
#define PLANET_H
using namespace std;

class planet
{
    public:
    // Variables
            double mass;
            double position[2];
            double velocity[2];
            double potential;
            double kinetic;
            double angular_momentum;
            string name;


    // Constructors and destructer
            planet();
            planet(double mass, double distance);
            planet(double mass, double pos_x, double pos_y, double vel_x, double vel_y);
            ~planet();

    // Functions
            double distance(planet& otherPlanet);
            void print_to_screen();
            double kinetic_energy();
            double find_angular_momentum();
};

#endif // PLANET_H
