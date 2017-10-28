#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "classes/planet.h"
#include "classes/solver.h"

using namespace std;

int main()
{
    // Planeter. Initialposisjoner og -hastigheter er tatt fra NASA.
    planet Sun(1, 0.0);
    // planet Mercury(1.65e-7, -1.944283745849790/10, -4.140558605944456/10, 1.981070958868529/100*365.242199, -1.055569430635730/100*365.242199);
    // planet Mercury(1.65e-7, 0.3075, 0, 0, 12.44); // Only used to find the pelihelion precession
    // planet Venus(2.45e-6, -6.965827638175602/10, 1.710703440855886/10,-4.764458045115461/1000*365.242199, -1.976876128946118/100*365.242199);
    planet Earth(3e-6, 8.498390784679897/10, 5.257531374377997/10,-9.287650987534323/1000*365.242199, 1.460685672528012/100*365.242199);
    // planet Mars(3.3e-7, -1.593973673813533, 4.757712766291348/10, -3.434118904608629/1000*365.242199, -1.222280300988921/100*365.242199);
    // planet Jupiter(9.5e-4, -4.552716295312017, -2.968973861579031, 4.033115625421092/1000*365.242199,-5.963304467147289/1000*365.242199 );
    // planet Saturn(2.75e-4, -3.105764883730929/10,-1.005084147978311*10, 5.270148789381274/1000*365.242199, -1.896682210241884/10000*365.242199);
    // planet Uranus(4.4e-5, 1.784547232578877*10, 8.836566820847164, -1.774235817965277/1000*365.242199,3.341325107975804/1000*365.242199);
    // planet Neptune(5.15e-5, 2.862106161908984*10,-8.797190768463262,9.009535641145148/10000*365.242199, 3.019141208789181/1000*365.242199);
    // planet Pluto(6.55e-9, 1.057139158383053*10, -3.170989354568712*10,3.045080571692537/1000*365.242199,3.440858972141450/10000*365.242199);

    solver solar_system(pow(10, 6), 5.0);
     solar_system.add_planet(Sun);
     // solar_system.add_planet(Mercury);
     // solar_system.add_planet(Venus);
     solar_system.add_planet(Earth);
     // solar_system.add_planet(Mars);
     // solar_system.add_planet(Jupiter);
     // solar_system.add_planet(Saturn);
     // solar_system.add_planet(Uranus);
     // solar_system.add_planet(Neptune);
     // solar_system.add_planet(Pluto);


    solar_system.Euler();
    solar_system.VelocityVerlet();
}
