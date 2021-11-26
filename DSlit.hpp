#ifndef __DSlit_hpp__
#define __DSlit_hpp__

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

	cx_double dt_;

	//Then, we declare also the constructor

	DSlit(double T_in, int M_in, double v0_in, double h_in, cx_double dt_in);

	//Finally, we declare some methods for calculating some important things

	void create_V(cx_mat& V);

	void create_AB(sp_cx_mat& A, sp_cx_mat& B, cx_mat V);

	void evolve_t(sp_cx_mat A, sp_cx_mat B, cx_vec& u);


};
#endif
