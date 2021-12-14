# Project-5

We've used this repository to generate plots for supporting our report about a particle in a box going through one, two and three slits configurations.

In the folder named "Include" you will find an .hpp file that you must download for executing every .cpp, which you will find in the folder "Source". In folder "Phyton" you will find every python file and every data file used to make the plots, which are also in that folder. Lastly, in the folder "Parameters settings" you can find the files that contains the parameters values for every simulation.

Now we are going to detail a little bit each .cpp file.

First, we have the file "DSlit.cpp" which define the main class that we will use later. This class stores all the main parameters and contain the main functions that are used to evolve the system and obtain the data we need for making the plots. This file is not meant to be directly executed.

In the file "Consistency_check.cpp" we evolve the system in a two slits configuration. With it, we generate the data files stored in the folder "Consistency check" (in Python/txt). What changes between the two .txt files is the introduced parameters values. With these data files we generate the plot "Consistency_check" using the python file "Consistency_check.py".

In the files "2DReal.cpp" and "2DImag.cpp" we study how the real and imaginary parts (respectively) of the system evolve in time. We do that using only the two slits configurations. With them we produce the plots "Colourmap_Re_t0", "Colourmap_Re_t1", "Colourmap_Re_t2", "Colourmap_Im_t0", "Colourmap_Im_t1" and "Colourmap_Im_t2", using the python codes "Colourmap.py" and the data files "Colourmap_re.txt" and "Colourmap_im.txt" (in Python/txt). Using also those .txt files and the python file "Animation.py" we produce the videos "Re_animation" and "Im_animation".

And, finally using the file "2DProbability.cpp" we study the 2D and 1D probability of finding the particle in some position (x, y) (in the case of 1D probability, finding the particle at some y point along a "screen" placed at x = 0.8) at each time. Changing the number of slits in the potential, we generate different data files stored in the folder "Colourmap p" (in Python/txt). Using all of them and the python file "1Dprob.py", we produce the plots "1Dprob_1slit", "1Dprob_2slits" and "1Dprob_3slits". In addition, with the file named "Colourmap_p_2slits.txt" and the python file "Colourmap.py", we produce the plots "Colourmap_p_2slits_t0", "Colourmap_p_2slits_t1" and "Colourmap_Im_t2" and, with the same .txt and the python file "Animation.py" we produce the videos named "p_2slits_animation". 

For building and execute each of the cpp mentioned before (except for the DSlit one, as we already said), as, for example "Consistency_check.cpp", you need to have all the files from the folders "Source", "Include" and "Parameters settings" in the same folder of your computer and write:

Build: g++ Consistency_check.cpp DSlit.cpp -o Consistency_check.exe -larmadillo
Run: ./Consistency_check.exe
