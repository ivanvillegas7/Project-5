#include "DSlit.hpp"


int main(){

	//First, we extract the needed parameters from an input file

	vec SP;

        SP.load("Simulation Parameters.txt", raw_ascii);



	//After that, we create our system and the needed matrices

        DSlit my_system( SP(2) , 1/SP(0), SP(9), SP(0), SP(1), SP(3), SP(4), SP(5), SP(6), SP(7), SP(8));

        int N = (my_system.M_ - 2) * (my_system.M_ - 2);

        sp_cx_mat A(N, N);

        sp_cx_mat B(N, N);

        cx_mat V(my_system.M_ - 2, my_system.M_ - 2);

        my_system.create_V(V , SP(10), SP(11), SP(12), SP(13));

        my_system.create_AB(A, B , V);



	//Then, we set up the initial state

	cx_vec u(N);

	my_system.initial_state(u);



	//Finally, we can evolve the system in one step in time

	double t = 0;

	while(t <= T){

		my_system.evolve_u(A, B, u);

		t++;

	}

	return 0;

}
