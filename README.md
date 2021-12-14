# Project-5

We've used this repository to generate plots for supporting our report about a particle in a box going through one, two and three slits configurations.

In the folder named "Include" you will find an .hpp file that you must download for executing every .cpp, which you will find in the folder "Source". In folder "Phyton" you will find every .py file and every data file used to make the plots, which are also in that folder. Lastly, in the folder "Parameters settings" you can find the files that contains the parameters values for every simulation.

Now we are going to detail a little bit each .cpp file.

First, we have the file "DSlit.cpp" which define the main classe that we will use later. This class store all the main parameters and contain the main functions that are used to evolve the system and obtain the data we need for making the plots. This file is nor meant to be directly executed.

In the file "Consistency_check.cpp" we evolve the system in a two slits configuration. With it, we generate the .txt files stored in the folder "Consistency check" (in Python/txt files). What changes between the two .txt files is the introduced parameters values. With this .txt we generate the plot "Consistency_check".

In the files "2DReal.cpp" and "2DImag.cpp" we study the case of 100 particles trapped in our device. With them we produce the plots "Resonance_1" and "Resonance_2", using the python codes "Resonance_1.py" and "Resonance_2.py" (respectively) and the .txt files stored in the folder Resonance (in Python/txt files).

And, finally using the file "Two_particles_RK4.cpp" we simulate the case of having two particles in our trap. Changing different desired parameters we generate different .txt files store in the folder Two particles (in Python/txt files) and with them, we produce the rest of the plots of the folder Plots (in Python) using the rest of the pyhton files.

For building and execute each of the cpp mentioned before (except for the Particle and the PenningTrap one, as we already said), as, for example "Two_particles_RK4.cpp", you need to have all the files from the folders "Source" and "Include" in the same folder of your computer and write:

Build: g++ Two_particles_RK4.cpp PenningTrap.cpp Particle.cpp -o Two_particles_Rk4.exe -larmadillo Run: ./Two_particles_RK4.exe
