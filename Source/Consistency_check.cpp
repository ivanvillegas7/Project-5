

#include "DSlit.hpp"


int main(){

	ofstream ofile;
	ofile.open("Consistency_check.txt");  //That is an example name, but with this program we have generated four different files
	ofile << scientific;



	//First, we extract the needed parameters from an input file

	vec SP;

        SP.load("Simulation_parameters0.txt", raw_ascii);



	//After that, we create our system and the needed matrices

        DSlit my_system( SP(2) , 1/SP(0)+1, SP(9), SP(0), SP(1), SP(3), SP(4), SP(5), SP(6), SP(7), SP(8));

        int N = (my_system.M_ - 2) * (my_system.M_ - 2);

        sp_cx_mat A(N, N);

        sp_cx_mat B(N, N);

        cx_mat V(my_system.M_ - 2, my_system.M_ - 2);

        my_system.create_V(V , SP(10), SP(11), SP(12), SP(13));

	cout << "V done" << endl;

        my_system.create_AB(A, B , V);

	cout << "A and B done" << endl;





	//Then, we set up the initial state

	cx_vec u(N);

	my_system.initial_state(u);

	cout << size(B) << "  " << size (u);



	//We define some elements to store and to count the steps


	double t = 0.0;

	int n = 1;

	/*cx_vec P(1);

	P(0) = my_system.probability(u);

	cx_vec p(1);

	P.print("Probability:");*/

	ofile << (1.0 - real(my_system.probability(u))) << endl;



	//Finally, we can evolve the system in one step in time

	while(t < my_system.T_){

		my_system.evolve_u(A, B, u);

		ofile << (1.0 - real(my_system.probability(u))) << endl;

	    	/*p(0) = my_system.probability(u);
    		P.insert_rows(P.n_rows, p.row(0));*/

		t = t + my_system.dt_;

		n++;

	}


	/*P.print("Probability:");

	P.save("Consistency_check.txt");*/

	ofile.close();

	return 0;

}
