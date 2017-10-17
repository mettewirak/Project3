#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "planet.h"
#include "solver.h"

using namespace std;
std::ofstream ofile;

int without_classes();

int main()
{
    // without_classes();

    // int dimension = 2;

    planet Earth(1, 1.0, 0.0, 0.0, 2*M_PI, -4*M_PI*M_PI, 0.0);
    planet Sun(1, 0.0, 0.0, 0.0, 0.0);
    //Earth.print_to_screen();
    //solver current(1000, 5.0);
    //current.VelocityVerlet(Earth);
    //current.print_to_screen();

    double temp = Earth.distance(Sun);

    cout << "Avstanden mellom Earth og Sun er " << temp << " AU." << endl;

}

int without_classes(){

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
