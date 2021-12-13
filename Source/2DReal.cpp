#include "DSlit.hpp"


int main() {

	//First we load the parameters that we will use for this simulation

	vec SP;
	SP.load("Simulation_parameters2.txt", raw_ascii);


	//Now, using them, we create our class

	DSlit my_system(SP(2), 1/SP(0) + 1.0, SP(9), SP(0), SP(1), SP(3), SP(4), SP(5), SP(6), SP(7), SP(8));



	//We set the dimension of A and B and create the matrices and vectors where we will store everything

	int N = (my_system.M_ - 2) * (my_system.M_ - 2);

	sp_cx_mat A(N, N);

	sp_cx_mat B(N, N);

	cx_mat V(my_system.M_ - 2, my_system.M_ - 2);

	cx_vec u(N);

	cube u_n(my_system.M_ - 2, my_system.M_ - 2, (int)round( (my_system.T_ / my_system.dt_) + 1 ));

        cx_mat U(my_system.M_ - 2, my_system.M_ - 2);



	//After that, we fill the matrices V, A and B and we set up the initial state

	my_system.create_V(V, 3,  SP(10), SP(11), SP(12), SP(13));

	my_system.create_AB(A, B, V);

	my_system.initial_state(u);



	//Some counters and variables that we'll use later

	double t = 0.0;

	int l = 0;

	int k;


	//We evolve the system in time

	while (t <= (my_system.T_ + my_system.dt_)) {

		for (int i = 0; i < my_system.M_ - 2; i++) {

			for (int j = 0; j < my_system.M_ - 2; j++) {

				k = i + j * (my_system.M_ - 2);  //Here we calculate the position k of the a and b vectors that corresponds to the element ij of the matrix U

				U(i, j) = real(u(k));  //We transform the vector u into a matrix U to be able to store it in a cube with the rest time steps (only the real part in this case)

			}

		}

		u_n.slice(l) = U;  //We store the real part of each time step before evolving the system because we want to store also the initial state

		my_system.evolve_u(A, B, u);  //Then we evolve the system


		//We upload the counter for time and for the step

		t += my_system.dt_;
		l++;

	}


	//Finally, we save the cube that contains all the data

	u_n.save("Colourmap_re.txt");

	return 0;

}
