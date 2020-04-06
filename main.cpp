#include <iostream>
#include <valarray>

//Random number generation
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "matrix.hpp"
#include "matrixG.hpp"
#include "matrixC.hpp"
#include "matrixD.hpp"


int main(int argc, char* argv[]){

	//Testing Matrix class	
	Matrix m0;
	std::cout << "m0\n" << m0 << std::endl;
	
	Matrix m1(2, 2);
	std::cout << "m1\n" << m1 << std::endl;

	Matrix m2(m1);
	std::cout << "m2\n" << m2 << std::endl;

	std::valarray<int> temp(1, 6);
	Matrix m3(3, 2, temp);
	std::cout << "m3\n" << m3 << std::endl;



	//Testing Matrix G class
	MatrixG g0;
	std::cout << "g0\n" << g0 << std::endl;

	MatrixG g1(3, 2);
	std::cout << "g1\n" << g1 << std::endl;

	MatrixG g2(g1);
	std::cout << "g2\n" << g2 << std::endl;

	std::valarray<int> temp2(2, 12);
	MatrixG g3(2, 6, temp2);
	std::cout << "g3\n" << g3 << std::endl;


	//Testing Matrix C class



	//Testing Matrix D class

	return 0;
}
