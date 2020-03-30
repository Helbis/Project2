#define TOP_LIMIT_OF_NUMBER 100


class Matrix{
	private:
		int cols, rows;					//Number of rows & columns
		std::vector<int> data;			//Data accessed with [i][j] where it's actually (i*cols + j)

	public:
		Matrix(void);					//Matrix 0x0 -> NULL
		Matrix(Matrix other);			//Matrix copied from other
		Matrix(int r, int c);			//Matrix with random values
		~Matrix(void);

		void operator =(Matrix other);		//Assign to the matrix other one
		std::string operator <<(void);		//Print matrix row by row
		Matrix operator +(Matrix other);	//Add to matrix another matrix
		Matrix operator -(Matrix other);	//Subtract from matrix another matrix
		Matrix operator *(Matrix other);	//Multiply matrix by matrix, give back new matrix
		Matrix operator *(int var);			//Multiply matrix by a scalar 
		void operator +=(Matrix other);		//Add to the current matrix other one
		void operator -=(Matrix other);		//Subtract from matrix other one
		void operator *=(Matrix other);		//Multiply matrix by the other one
		
};


//Definitions

Matrix::Matrix(void){
	rows = cols = 0;

	data.shrink_to_fit();
}


Matrix::Matrix(Matrix other){
	//Clear matrix
	data.clear();

	rows = other.getRow();
	cols = other.getColumn();

	for(int i=0; i<cols; i++){
		for(int j=0; j<rows; j++){
			data.push_back(other[i*cols + j]); 
		}
	}	
	
	data.shrink_to_fit();
}


Matrix::Matrix(int r, int c){
	rows = r;
	cols = c;

	/* initialize random seed: */
	srand(time(NULL));	

	for(int i=0; i<cols; i++){
		for(int j=0; j<rows; j++){
			//Fill with random numbers from <0, 99>
			data.push_back(rand() % TOP_LIMIT_OF_NUMBER);
		}
	}

	data.shrink_to_fit();
}


Matrix::~Matrix(void){

}


//Functions
void Matrix::operator =(Matrix other){

}


std::string Matrix::operator <<(void){

}


Matrix Matrix::operator +(Matrix other){

}


Matrix Matrix::operator -(Matrix other){

}


Matrix Matrix::operator *(Matrix other){

}


Matrix Matrix::operator *(int var){

}


void Matrix::operator +=(Matrix other){

}


void Matrix::operator -=(Matrix other){

}


void Matrix::operator *=(Matrix other){

}
