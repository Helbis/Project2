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


	std::valarray<int> v1(1, 4);
	std::valarray<int> v2(2, 2);
	std::valarray<int> v3 = v1;
	v3 *= v2;
	
	for(size_t i=0; i<v1.size(); i++){
		std::cout << v1[i] << ", ";
	}

	std::cout << std::endl;	
	for(size_t i=0; i<v2.size(); i++){
		std::cout << v2[i] << ", ";
	}

	std::cout << std::endl;
	for(size_t i=0; i<v3.size(); i++){
		std::cout << v3[i] << ", ";
	}

	
	std::cout << std::endl;

	return 0;
}
