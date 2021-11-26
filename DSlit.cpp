#include "DSlit.hpp"

DSlit::DSlit(double T_in, int M_in, double v0_in, double h_in, cx_double dt_in) {

    //We assign the introduced values to the member variables

    T_ = T_in;
    M_ = M_in;
    v0_ = v0_in;
    h_ = h_in;
    dt_ = dt_in;

}

//Method that creates a the potential in a matrix 

void DSlit::create_V(cx_mat& V) {

	//esto hay que retocarlo, poner las paredes y las slits xdd lmao

	V.diag(0) = cx_vec(M_-2 , fill::ones);

	V = v0_ * V;

}

void DSlit::create_AB(sp_cx_mat& A , sp_cx_mat& B, cx_mat V) {

	int N = (M_ - 2) * (M_ - 2);

	int k;

	cx_double r = 1.0 * 1.0i * dt_ / (2 * h_ * h_);
	
	cx_vec a(N);

	cx_vec b(N);

	for (int i = 0; i < M_ - 2; i++) {

		for (int j = 0; j < M_ - 2; j++) {

			k = i + j * (M_ - 1);

			a[k] = 1.0 + 4.0 * r + 1.0i * dt_ * V(i, j) * 0.5;

			b[k] = 1.0 - 4.0 * r - 1.0i * dt_ * V(i, j) * 0.5;

		}

	}

	cx_vec vecr(N-1);

	vecr.fill(r);

	cx_vec vecr2(N-3);

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

