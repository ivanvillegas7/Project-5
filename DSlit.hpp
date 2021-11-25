#ifndef __DSlit_hpp__
#define _DSslist_hpp__

#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

class DSlit {

public:

	//First we declare the member variables

	double T_;

	int M_;

	double v0_;

	double h_;

	double dt_;

	//Then, we declare also the constructor

	DSlit(double T_in, int M_in, double v0_in , double h_in , double dt_in);

		//Finally, we declare some methods for calculating some important things

	void create_V(mat& V);

	void create_AB(cx_mat& A, cx_mat& B, mat V);
		

};


#endif
