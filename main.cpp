#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "classes/planet.h"
#include "classes/solver.h"

using namespace std;
std::ofstream ofile;

int withoutClasses_VelocityVerlet();

int main()
{
    // Planeter. Antar her at initialfarten ikke påvirkes av de andre planetene.
    planet Sun(1, 0.0);
    //planet Mercury(1.65e-7, -1.944283745849790/10, -4.140558605944456/10, 1.981070958868529/100*365.242199, -1.055569430635730/100*365.242199);
    planet Mercury(1.65e-7, 0.3075, 0, 0,12.44);
    planet Venus(2.45e-6, -6.965827638175602/10, 1.710703440855886/10,-4.764458045115461/1000*365.242199, -1.976876128946118/100*365.242199);
    planet Earth(3e-6, 8.498390784679897/10, 5.257531374377997/10,-9.287650987534323/1000*365.242199, 1.460685672528012/100*365.242199);
    planet Mars(3.3e-7, -1.593973673813533, 4.757712766291348/10, -3.434118904608629/1000*365.242199, -1.222280300988921/100*365.242199);
    planet Jupiter(9.5e-4, -4.552716295312017, -2.968973861579031, 4.033115625421092/1000*365.242199,-5.963304467147289/1000*365.242199 );
    planet Saturn(2.75e-4, -3.105764883730929/10,-1.005084147978311*10, 5.270148789381274/1000*365.242199, -1.896682210241884/10000*365.242199);
    planet Uranus(4.4e-5, 1.784547232578877*10, 8.836566820847164, -1.774235817965277/1000*365.242199,3.341325107975804/1000*365.242199);
    planet Neptune(5.15e-5, 2.862106161908984*10,-8.797190768463262,9.009535641145148/10000*365.242199, 3.019141208789181/1000*365.242199);
    planet Pluto(6.55e-9, 1.057139158383053*10, -3.170989354568712*10,3.045080571692537/1000*365.242199,3.440858972141450/10000*365.242199);

    solver now;
     now.add_planet(Sun);
     now.add_planet(Mercury);
     /*now.add_planet(Venus);
     now.add_planet(Earth);
     now.add_planet(Mars);
     now.add_planet(Jupiter);
     now.add_planet(Saturn);
     now.add_planet(Uranus);
     now.add_planet(Neptune);
     now.add_planet(Pluto);
     */

//    now.Euler();
    now.VelocityVerlet();

// Kjør noe.
}
/*

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
*/
