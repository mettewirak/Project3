#ifndef PLANET_H
#define PLANET_H

class Planet
{
    private:

    protected:

        public:
    // Variables
            double mass;
            double position[2];
            double velocity[2];
            double acceleration[2];

    // Constructors and destructer
            Planet();
            Planet(double mass, double pos_x, double pos_y, double vel_x, double vel_y, double acc_x, double acc_y);

            ~Planet();

    // Functions
            double radius_to_sun(double position[2]);
            void print_to_screen();
};

#endif // PLANET_H
