

#include "DSlit.hpp"


int main(){

	//First, we extract the needed parameters from an input file

	vec SP;

        SP.load("Simulation_parameters0.txt", raw_ascii);



	//After that, we create our system and the needed matrices

        DSlit my_system( SP(2) , 1/SP(0)+1, SP(9), SP(0), SP(1), SP(3), SP(4), SP(5), SP(6), SP(7), SP(8));

        int N = (my_system.M_ - 2) * (my_system.M_ - 2);

        sp_cx_mat A(N, N);

        sp_cx_mat B(N, N);

        cx_mat V(my_system.M_ - 2, my_system.M_ - 2);

        my_system.create_V(V, 2, SP(10), SP(11), SP(12), SP(13));

        my_system.create_AB(A, B , V);

	//Then, we set up the initial state

	cx_vec u(N);

	my_system.initial_state(u);

	//We define some elements to store the deviation of the total probability from 1.0

	double t = 0.0;

	vec P(1);

	P(0) = abs(1.0 - real(my_system.probability(u)));

	vec p(1);

	//Finally, we can evolve the system and store the deviation of the total probability from 1.0

	while(t < my_system.T_){

		my_system.evolve_u(A, B, u);
	    	p(0) = abs( 1.0 - real(my_system.probability(u)) );
    		P.insert_rows(P.n_rows, p.row(0));

		t = t + my_system.dt_;

	}

	P.save("Consistency_check0.txt", raw_ascii);

	return 0;

}
