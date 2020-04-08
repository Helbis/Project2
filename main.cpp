#include <iostream>
#include <valarray>		/* std::valarray */
#include <string>		/* std::to_string, std::string */
#include <boost/lexical_cast.hpp>	/* boost::lexical_cast<string> (any_type)  */

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

	// Declaring float 
	float f_val = 10.5; 
  
	// Declaring int 
	int i_val = 17; 
     
	// lexical_cast() converts a float into string 
	std::string strf = boost::lexical_cast<std::string>(f_val);  
     
	// lexical_cast() converts a int into string 
	std::string stri = boost::lexical_cast<std::string>(i_val);  
     
	// Displaying string converted numbers 
	std::cout << "The float value in string is : "; 
	std::cout << strf << std::endl; 
	std::cout << "The int value in string is : "; 
	std::cout << stri << std::endl; 

	return 0;
}
