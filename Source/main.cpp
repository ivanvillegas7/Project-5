#include "DSlit.hpp"


int main() {

	vec SP;
	SP.load("Simulation_parameters.txt", raw_ascii);

	//(int)(1 / SP(0))

	DSlit my_system(SP(2), 1/SP(0) + 1.0, SP(9), SP(0), SP(1), SP(3), SP(4), SP(5), SP(6), SP(7), SP(8));

	int N = (my_system.M_ - 2) * (my_system.M_ - 2);

	sp_cx_mat A(N, N);

	sp_cx_mat B(N, N);

	cx_mat V(my_system.M_ - 2, my_system.M_ - 2);

	my_system.create_V(V, SP(10), SP(11), SP(12), SP(13));

	my_system.create_AB(A, B, V);

	A.brief_print();

	cx_vec u(N);

	my_system.initial_state(u);

	//my_system.probability

	/*
	
	double t = 0.0;

	cx_cube u_n(my_system.M_ - 1, my_system.M_ - 1, (int)round(my_system.T_));

	cx_mat U(my_system.M_ - 1, my_system.M_ - 1);

	//vec v;

	int k;

	while (t <= my_system.T_) {

		my_system.evolve_u(A, B, u);

		for (int i = 1; i < my_system.M_ - 1; i++) {

			for (int j = 1; j < my_system.M_ - 1; j++) {

				k = (i - 1) + (j - 1) * (my_system.M_ - 2);

				U(i, j) = u(k);
			

			}

		}

		u_n.slice(t) = U;

		t++;
	}
	*/
	

	return 0;

}