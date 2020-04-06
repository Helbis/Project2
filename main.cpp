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
	
	Matrix m0;
	std::cout << "m0\n" << m0 << std::endl;
	
	Matrix m1(2, 2);
	std::cout << "m1\n" << m1 << std::endl;

	Matrix m2(m1);
	std::cout << "m2\n" << m2 << std::endl;

	std::valarray<int> temp(1, 6);
	Matrix m3(3, 2, temp);
	std::cout << "m3\n" << m3 << std::endl;

	return 0;
}
