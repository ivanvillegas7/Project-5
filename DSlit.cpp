#include "DSlit.hpp"


DSlit::DSlit(double T_in, int M_in, double v0_in, double h_in, cx_double dt_in, double xc_in, double sx_in, double px_in, double yc_in, double sy_in, double py_in) {

	//We assign the introduced values to the member variables

	T_ = T_in;
	M_ = M_in;
	v0_ = v0_in;
	h_ = h_in;
	dt_ = dt_in;
	xc_ = xc_in;
	sx_ = sx_in;
	px_ = px_in;
	yc_ = yc_in;
	sy_ = sy_in;
	py_ = py_in;

}




//Method that creates a the potential in a matrix form

void DSlit::create_V(cx_mat& V, double w, double s, double a, double xpos) {

	V.zeros(M_ - 2, M_ - 2);

	int W = (int)round((M_ - 3) * w / 2);

	int S = (int)round((M_ - 3) * s / 2);

	int A = (int)round((M_ - 3) * a);

	int XPOS = (int)round((M_ - 3) * xpos);

	for (int j = (XPOS - W); j <= (XPOS + W); j++) {

		for (int i = 0; i < (XPOS - (S + A)); i++) {

			V(i, j) = v0_;

		}

		for (int i = (XPOS - S); i <= (XPOS + S); i++) {

			V(i, j) = v0_;

		}

		for (int i = (XPOS + (S + A) + 1); i < (M_ - 2); i++) {

			V(i, j) = v0_;

		}

	}

}





void DSlit::create_AB(sp_cx_mat& A, sp_cx_mat& B, cx_mat V) {

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



	cx_vec vecr(M_ - 3);
	vecr.fill(r);

	cx_vec vecr2(M_ - 2);
	vecr2.fill(r);


	sp_cx_mat A1(M_ - 2, M_ - 2);
	A1.diag(1) = -vecr;
	A1.diag(-1) = -vecr;

	sp_cx_mat A2(M_ - 2, M_ - 2);
	A2.diag(0) = -vecr2;

	sp_cx_mat A3(M_ - 2, M_ - 2);


	sp_cx_mat Aa = join_horiz(A1, A2, A3);
	sp_cx_mat Ab = join_horiz(A2, A1, A2);
	sp_cx_mat Ac = join_horiz(A3, A2, A1);

	A = join_vert(Aa, Ab, Ac);
	B = -1.0 * join_vert(Aa, Ab, Ac);

	A.diag(0) = a;

	B.diag(0) = b;


}




void DSlit::evolve_u(sp_cx_mat A, sp_cx_mat B, cx_vec& u) {

	cx_vec b = B * u;

	u = spsolve(A, b);

}




cx_double DSlit::probability(cx_vec& u) {

	cx_double p = 0.0;

	int k;

	for (int i = 0; i < M_ - 2; i++) {

		for (int j = 0; j < M_ - 2; j++) {

			k = i + j * (M_ - 1);

			p += (std::conj(u(k)) * u(k));

		}

	}

	return(p);

}




void DSlit::initial_state(cx_vec& u) {

	//Aquí pondremos la función que crea el estado inicial xd, no da risa

	vec x = linspace(0, 1, M_ - 1);
	vec y = linspace(0, 1, M_ - 1);

	for (int i = 0; i < M_ - 1; i++) {

		for (int j = 0; j < M_ - 1; j++) {

			u(i, j) = exp(-(x(i) - xc_) * (x(i) - xc_) / (2 * sx_ * sx_) - (y(j) - yc_) * (y(j) - yc_) / (2 * sy_ * sy_) + 1.0i * px_ * (x(i) - xc_) + 1.0i * py_ * (y(j) - yc_));

		}

	}

	if (roundf( norm(probability(u)) * 100000000.0) / 100000000.0 != 1) {
		
	u = u * sqrt(1 / norm(probability(u)));

	}

}