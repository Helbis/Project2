#include <iostream>
#include <valarray>		/* std::valarray */
#include <string>		/* std::to_string, std::string */

//Random number generation
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//My classes
#include "matrixT.hpp"
#include "matrixTG.hpp"
#include "matrixTC.hpp"
#include "matrixTD.hpp"
#include "reduce.hpp"


int main(int argc, char* argv[]){

	Reduce<float> mat(2, 2, {-1.1, 2.0, 1.3, -12.0});
	MatrixTD<float> pat(2);

	std::cout << "\nmat : \n" << mat;
	std::cout << "\npat : \n" << pat;

	mat.pow(2);
	pat.pow(2);
	std::cout << "\nmat.pow(2) : \n" << mat;
	std::cout << "\npat.pow(2) : \n" << pat;

	mat += pat;
	std::cout << "\nresult : \n" << mat;
	
	return 0;
}
