#include "DSlit.hpp"

//Here we define the class "DSlit"

DSlit::DSlit(double T_in, int M_in, double v0_in, double h_in, double dt_in, double xc_in, double sx_in, double px_in, double yc_in, double sy_in, double py_in) {

	//We assign the introduced values to the member variables

	T_ = T_in;
	M_ = (int)round(M_in);  //In here we just round the imput value for the given M_ and set that rounded value as an integer just in case it was not
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




//Method that creates a the potential in a matrix form for n slits, where n can take the values 1, 2 or 3

void DSlit::create_V(cx_mat& V, int n, double w, double s, double a, double xpos) {

	//First we create a matrix full of zeros

	V.zeros(M_ - 2, M_ - 2);


	//Now we transform the given distances in "numbers of coloums" (we will round them later so they are integers)

	double W = (M_ - 3) * w / 2;  //Width of the wall

	double S = (M_ - 3) * s / 2;  //Separation between slits

	double A = (M_ - 3) * a / 2;  //Slit aperture

	double XPOS = (M_ - 3) * xpos;  //Position of the wall

	double YHALF = (M_ - 3) * 0.5;  //Position of the half of the matrix



	//Now we start to put potential where it should be

	for (int j = (int)round(XPOS - W); j <= (int)round(XPOS + W); j++) {

		//First the case for one slit

		if (n == 1){

			for (int i = 0; i < (int)round(YHALF - A); i++){

				V(i,j) = v0_;

			}

			for (int i = ( (int)round(YHALF + A) + 1 ); i < M_ - 2; i++){

                        	        V(i,j) = v0_;

                        }


        	}


		//Now we'll write the two slits case

	        if (n == 2){

			for (int i = 0; i < (int)round(YHALF - (S + 2*A)); i++) {

                                V(i, j) = v0_;

                        }

                        for (int i = (int)round(YHALF - S); i <= (int)round(YHALF + S); i++) {


                                V(i, j) = v0_;

                        }

                        for (int i = ( (int)round(YHALF + (S + 2*A)) + 1 ); i < (M_ - 2); i++) {

                                V(i, j) = v0_;

                        }


		}


		//Finally, we write the 3-slits case

		if (n == 3){

			for (int i = 0; i < (int)round(YHALF - (2*S + 3*A)); i++) {

                                V(i, j) = v0_;

                        }

                        for (int i = (int)round(YHALF - (2*S + A)); i < (int)round(YHALF - A); i++) {

                                V(i, j) = v0_;

                        }

                        for (int i = ( (int)round(YHALF + A) + 1 ); i <= (int)round(YHALF + (2*S + A)); i++) {

                                V(i, j) = v0_;

                        }


                        for (int i = ( (int)round(YHALF + (2*S + 3*A)) + 1 ); i < (M_ - 2); i++) {

                                V(i, j) = v0_;

                        }

		}

	}

}





void DSlit::create_AB(sp_cx_mat& A, sp_cx_mat& B, cx_mat V) {

	int N = (M_ - 2) * (M_ - 2);

	int k;

	cx_double r = 1.0 * 1.0i * dt_ / (2 * h_ * h_);

	cx_vec veca(N);

	cx_vec vecb(N);

	for (int i = 0; i < M_ - 2; i++) {

		for (int j = 0; j < M_ - 2; j++) {

			k = i + j * (M_ - 2);

			veca(k) = 1.0 + 4.0 * r + 1.0i * dt_ * V(i, j) * 0.5;

			vecb(k) = 1.0 - 4.0 * r - 1.0i * dt_ * V(i, j) * 0.5;

		}

	}

	cx_vec vecr(N - 1);
	vecr.fill(r);

	cx_vec vecr2(N - M_ + 2);
	vecr2.fill(r);

	A.diag(0) = veca;
	A.diag(1) = -vecr;
	A.diag(-1) = -vecr;
	A.diag(M_ - 2) = -vecr2;
	A.diag(-(M_ - 2)) = -vecr2;

	B.diag(0) = vecb;
	B.diag(1) = vecr;
	B.diag(-1) = vecr;
	B.diag(M_ - 2) = vecr2;
	B.diag(-(M_ - 2)) = vecr2;


	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (((i % (M_ - 2)) == 0) && (((j+1) % (M_ - 2)) == 0)) {


				A(i, j) = 0;

				B(i, j) = 0;

			}

		}

	}

}




void DSlit::evolve_u(sp_cx_mat A, sp_cx_mat B, cx_vec & u) {

		cx_vec b = B * u;

		u = spsolve(A, b);

}




cx_double DSlit::probability(cx_vec u){

        cx_double p = 0.0;

        for (int j = 0; j < (u.n_elem); j++) {

        	p += (conj(u(j)) * u(j));

        }

        return(p);

}




void DSlit::initial_state(cx_vec& u) {

        vec y = linspace(0, 1, M_);

        vec x = linspace(0, 1, M_);

        int k;

        for (int i = 1; i < M_ - 1; i++) {

        	for (int j = 1; j < M_ - 1; j++) {

                	k = (i-1) + (j-1) * (M_ - 2);

			u(k) = exp(-( (x(j) - xc_) * (x(j) - xc_) / (2 * sx_ * sx_) ) - ( (y(i) - yc_) * (y(i) - yc_) / (2 * sy_ * sy_ )) + 1.0i * px_ * (x(j) - xc_) + 1.0i * py_ * (y(i) - yc_));

                }

        }

        u = u * sqrt( 1 / (real(probability(u))));

}
