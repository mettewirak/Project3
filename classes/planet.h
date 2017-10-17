#ifndef PLANET_H
#define PLANET_H

class planet
{
    public:
    // Variables
            double mass;
            double position[2];
            double velocity[2];

    // Constructors and destructer
            planet();
            planet(double mass, double pos_x, double pos_y, double vel_x, double vel_y);
            ~planet();

    // Functions
            double distance(planet otherPlanet);
            double radius_to_sun(double position[2]);
            void print_to_screen();
};

#endif // PLANET_H
