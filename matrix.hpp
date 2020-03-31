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


		//Getters
		int getRow(void);
		int getCol(void);
		int get_rawData(void);	

		//Setters
		void setRow(int num);
		void setCol(int num);

		//Utility funcs
		int operator [](int i); 			//Returns a specific part of data


		/*
		For matrix algebra I used:

		https://en.wikipedia.org/wiki/Matrix_(mathematics)
		*/
		
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

	for(int i=0; i<data.size(); i++){
		//Fill with random numbers from <0, 99>
		data.push_back(rand() % TOP_LIMIT_OF_NUMBER);
	}

	data.shrink_to_fit();
}


Matrix::~Matrix(void){

}


//Functions
void Matrix::operator =(Matrix other){
	data.clear();	

	rows = other.getRow();
	cols = other.getCol();

	data = other.get_rawData();

	data.shrink_to_fit();
}


std::string Matrix::operator <<(void){
	std::string result;

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			result.push_back(std::to_string(data[i*cols + j) + ", ");
		}
		
		result.push_back("\n");
	}

	return result;
}


Matrix Matrix::operator +(Matrix other){
	Matrix result;

	if(rows == other.getRow() and cols == other.getCols()){
		//Add element to element
		for(int i=0; i<data.size(); i++){
			resultpush_back(data[i] + other[i]);
		}		
	}else{
		//Unable to add matrices
	}

	result.shrink_to_fit();
	return result;	
}


Matrix Matrix::operator -(Matrix other){
	Matrix result;

	if(rows == other.getRow() and cols == other.getCols()){
		//Subtract element from element
		for(int i=0; i<data.size(); i++){
			result.push_back(data[i] - other[i]);
		}		
	}else{
		//Unable to subtract matrices
	}

	result.shrink_to_fit();
	return result;	
}


Matrix Matrix::operator *(Matrix other){
	Matrix result;

	if(rows == other.getCols() and cols == other.getRow()){
		//Add element to element
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				//Row column rule	
			}
		}		
	}else{
		//Unable to multiply matrices
	}

	result.shrink_to_fit();
	return result;	
}


Matrix Matrix::operator *(int var){
	for(int i=0; i<data.size(); i++){
		data[i] *= var;
	}
}


void Matrix::operator +=(Matrix other){
	if(rows == other.getRow() and cols == other.getCols()){
		//Add to this matrix

		for(int i=0; i<data.size(); i++){
			data[i] += other[i];
		}

	}else{
		//Do nothing
	}
}


void Matrix::operator -=(Matrix other){

}


void Matrix::operator *=(Matrix other){
	
}
