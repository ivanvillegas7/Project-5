#include "DSlit.hpp"


int main(){
	
	DSlit my_system(10, 5, 100000, 0.1, 0.1);

	int N = (my_system.M_ - 2) * (my_system.M_ - 2);

	sp_cx_mat A(N, N);

	sp_cx_mat B(N, N);
	
	cx_mat V(my_system.M_ - 2, my_system.M_ - 2);

	my_system.create_V(V);

	my_system.create_AB(A, B , V);

	//V.brief_print();

	//A.brief_print();

	//B.brief_print();

	//V.print();

	//A.print();

	B.print();

}