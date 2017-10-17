#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "planet.h"
#include "solver.h"

using namespace std;
std::ofstream ofile;

int withoutClasses_VelocityVerlet();

int main()
{
    // without_classes();

    // Planeter. Antar her at initialfarten ikke påvirkes av de andre planetene.
    planet Sun(1, 0.0);
//    planet Mercury(1.65e-7, 0.39);
//    planet Venus(2.45e-6, 0.72);
    planet Earth(3e-6, 1.0);
//    planet Mars(3.3e-7, 1.52);
    planet Jupiter(9.5e-4, 5.20);
//    planet Saturn(2.75e-4, 9.54);
//    planet Uranus(4.4e-5, 19.19);
//    planet Neptune(5.15e-5, 30.06);
//    planet Pluto(6.55e-9, 39.53)

    solver now;

    now.add_planet(Sun);
    now.add_planet(Earth);
    now.add_planet(Jupiter);
    now.print_to_screen();
    now.VelocityVerlet();
}

int withoutClasses_VelocityVerlet(){

    int dim = 2;

    int integration_points = 1000;
    double final_time = 5.0;
    double dt = final_time/(double)integration_points;

    double **position, **speed, **acceleration;
    position = new double*[integration_points];
    speed = new double*[integration_points];
    acceleration = new double*[integration_points];
    for(int i=0; i<integration_points; i++){
        position[i] = new double [dim];
        speed[i] = new double [dim];
        acceleration[i] = new double [dim];
    }

    double G = 4*M_PI*M_PI;
    double M_sun = 1.0;
    double radius_es;

    for(int i=0; i<integration_points; i++){
        for(int j=0; j<dim; j++){
            position[i][j] = 0.0;
            speed[i][j] = 0.0;
            acceleration[i][j] = 0.0;
        }
    }

    // Set the initial values used.
    position[0][0] = 1.0;
    position[0][1] = 0.0;
    radius_es = sqrt(position[0][0]*position[0][0]+position[0][1]*position[0][1]);
    speed[0][0] = 0.0; // Vet at hastigheten må være perpendikular på radius
    speed[0][1] = sqrt(G*M_sun/radius_es);
    acceleration[0][0] = -G*M_sun*position[0][0]/(radius_es*radius_es*radius_es); // Dekomponerer krafta F.
    acceleration[0][1] = -G*M_sun*position[0][1]/(radius_es*radius_es*radius_es);

    // The iteration itself
    for(int i=0; i<(integration_points-1); i++){
        radius_es = sqrt(position[i][0]*position[i][0] + position[i][1]*position[i][1]);
        cout << "Radien er " << radius_es << "." <<endl;

        for(int j=0; j<dim; j++){
            position[i+1][j] = position[i][j] + dt*speed[i][j] + ((dt*dt)/2)*acceleration[i][j];
            acceleration[i+1][j] = -G*M_sun*position[i][j]/(radius_es*radius_es*radius_es);
            speed[i+1][j] = speed[i][j] + (dt/2)*(acceleration[i+1][j] + acceleration[i][j]);
        }
    }

    // PRINT
    ofile.open("Output_data.txt");
    ofile << "time\t x\t \ty \t\t speed_x\t speed_y\t accel_x\t accel_y " << endl;
    ofile << 0 << "\t" << position[0][0] << "\t \t" << position[0][1] << "\t \t" << speed[0][0] << "\t \t" << speed[0][1] << "\t" << acceleration[0][0] << "\t" << acceleration[0][1] << endl;
    for(int i=1; i<integration_points; i++){
        ofile << i << "\t" <<position[i][0] << "\t" << position[i][1] << "\t" << speed[i][0] << "\t" << speed[i][1] << "\t" << acceleration[i][0] << "\t" << acceleration[i][1] << endl;
    }
    ofile.close();

    cout << "Ferdig!" << endl;

    return 0;
}
