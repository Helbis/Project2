#include <iostream>
#include <valarray>

//Random number generation
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//Matrix classes
#include "matrixT.hpp"
#include "matrixTG.hpp"
#include "matrixTC.hpp"
#include "matrixTD.hpp"


int main(int argc, char* argv[]){

	//Testing Matrix class	
	MatrixT<int> m0;
	std::cout << "m0\n" << m0 << std::endl;
	
	MatrixT<int> m1(2, 2);
	std::cout << "m1\n" << m1 << std::endl;

	MatrixT<int> m2(m1);
	std::cout << "m2\n" << m2 << std::endl;

	std::valarray<double> temp(1, 6);
	MatrixT<double> m3(3, 2, temp);
	std::cout << "m3\n" << m3 << std::endl;

	return 0;
}
