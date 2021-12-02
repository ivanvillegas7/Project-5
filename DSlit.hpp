#ifndef __DSlit_hpp__
#define __DSlit_hpp__

#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include <complex>

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

	double xc_;
	
	double sx_;
	
	double px_;
	
	double yc_; 
	
	double sy_;
	
	double py_;

	//Then, we declare also the constructor

	DSlit(double T_in, int M_in, double v0_in, double h_in, cx_double dt_in, double xc_in, double sx_in, double px_in, double yc_in, double sy_in, double py_in);

	//Finally, we declare some methods for calculating some important things

	void create_V(cx_mat& V, double w, double s, double a, double xpos);

	void create_AB(sp_cx_mat& A, sp_cx_mat& B, cx_mat V);

	void evolve_t(sp_cx_mat A, sp_cx_mat B, cx_vec& u);

	void initial_state(cx_vec& u);

	cx_double probability(cx_vec& u);

};
#endif