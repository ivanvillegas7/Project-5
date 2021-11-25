#include "DSlijhbst.hpp"


int main(){
	
	DSlit my_system(10, 5, 100000, 0.1, 0.1);

	int N = (M - 2) * (M - 2);

	cx_mat A(N, N);

	cx_mat B(N, N);
	
	mat V = mat(my_system.M_ - 2, my_system.M_ - 2);

	my_system.create_V(V);

	my_system.create_AB(A, B);




}