#ifndef PLANET_H
#define PLANET_H

class Planet
{
	private:

	protected:

    public:
    // Variables
		double mass;
		double position[2]; // x and y
		double velocity[2]; // x and y

	// Constructors and destructer
		Planet();
        Planet(double m, double x, double y, double vx, double vy);

        ~Planet();

    // Functions

};

#endif // PLANET_H