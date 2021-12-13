#include "DSlit.hpp"


int main() {

	vec SP;
	SP.load("Simulation_parameters2.txt", raw_ascii);


	DSlit my_system(SP(2), 1/SP(0) + 1.0, SP(9), SP(0), SP(1), SP(3), SP(4), SP(5), SP(6), SP(7), SP(8));

	int N = (my_system.M_ - 2) * (my_system.M_ - 2);

	sp_cx_mat A(N, N);

	sp_cx_mat B(N, N);

	cx_mat V(my_system.M_ - 2, my_system.M_ - 2);

	my_system.create_V(V, 2,  SP(10), SP(11), SP(12), SP(13));

	my_system.create_AB(A, B, V);

	cx_vec u(N);

	my_system.initial_state(u);



	double t = 0.0;

	cube u_n(my_system.M_ - 2, my_system.M_ - 2, (int)round( (my_system.T_ / my_system.dt_) + 1 ));

	cx_mat U(my_system.M_ - 2, my_system.M_ - 2);

	int l = 0;

	int k;

	while (t <= (my_system.T_ + my_system.dt_)) {

		for (int i = 0; i < my_system.M_ - 2; i++) {

			for (int j = 0; j < my_system.M_ - 2; j++) {

				k = i + j * (my_system.M_ - 2);

				U(i, j) = u(k);

			}

		}

		u_n.slice(l) = real( conj(U) % U );

		my_system.evolve_u(A, B, u);

		t += my_system.dt_;
		l++;

	}

	u_n.save("Colourmap_p.txt");

	return 0;

}
