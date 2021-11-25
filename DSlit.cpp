#include "DSlit.hpp"

DSlit::DSlit(double T_in, int M_in, double v0_in, double h_in, double dt_in) {

    //We assign the introduced values to the member variables

    T_ = T_in;
    M_ = M_in;
    v0_ = v0_in;
    h_ = h_in;
    dt_ = dt_in;

}

//Method that creates a matrix (random or not) of spins filling it with 1 and -1

void DSlit::create_V(mat& V) {

    // meter v0 en la amtriz xd    

}

void DSlit::create_AB(cx_mat& A , cx_mat& B, mat V) {

	int N = (M_ - 2) * (M_ - 2);

	int k;

	cx_double r = 1.0 * 1i * dt_ / (2 * h_ * h_);
	
	cx_vec a(N, fill::zeros);

	cx_vec b(N, fill::zeros);

	for (int i = 0; i < M_ - 2; i++) {

		for (int j = 0; j < M_ - 2; j++) {

			k = i + j * (M_ - 1);

			a[k] = 1.0 + 4.0 * r + 1.0 * 1i * dt_ * V[i, j] / 2.0;

			b[k] = 1.0 - 4.0 * r - 1.0 * 1i * dt_ * V[i, j] / 2.0;

		}

	}

	cx_vec vecr(N);

	vecr.fill(r);

	cx_vec vecr2(N);

	vecr2.fill(r);


	A.diag(0) = a;
	A.diag(1) = -vecr;
	A.diag(3) = -vecr2;
	A.diag(-1) = -vecr;
	A.diag(-3) = -vecr2;

	B.diag(0) = b;
	B.diag(1) = vecr;
	B.diag(3) = vecr2;
	B.diag(-1) = vecr;
	B.diag(-3) = vecr2;

}
