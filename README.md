# Project3
Coursework in FYS4150 - Computational Physics at the University of Oslo.

We're implemented the numerical method Velocity Verlet, and partly forward Euler, to make a model of the solar system.

There are mostly functions in the solver-class for doing the different things implemented (adding a planet to the system, running 
the numerical methods, checking if the energy and angular momentum is conserved, finding the time usage of the numerical methods). 

However, there are a couple of things that has not yet been made into their own function:

- Choosing whether to only look at Newtonian forces or to include relativistic ones as well. 
To do this we have to different functions in the class solver, which are called force_general() and force_relativistic(). To differ
between which you are using, go into solver::VelocityVerlet and which. The functions are used 4 times, in lines 112, 113, 140 and 141.

- Finding the pelihelion precession of a planet.
Uncomment the following lines in solver::VelocityVerlet: 39-49, 96-98, 127-131, 174-177.
Also, the algorithm is only implemented for Mercury at this point. To run it with a different planet requires that the value in line 39
is changed. The value is found by dividing the number of days it takes for the planet to orbit once around the Earth by the number of
days in a (Earth)year. Also, only include the Sun and the one other planet is the solver. 

Should it be desirable to fix the Sun at origo (as we did in the start of the project), this can be done by commenting out line 54-66
in solver::VelocityVerlet.