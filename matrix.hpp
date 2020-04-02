#define TOP_LIMIT_OF_NUMBER 100


class Matrix{
	private:
		int cols, rows;					//Number of rows & columns
		std::vector<int> data;			//Data accessed with [i][j] where it's actually (i*cols + j)

	public:
		Matrix(void);					//Matrix 0x0 -> NULL
		Matrix(Matrix &other);			//Matrix copied from other
		Matrix(int r, int c);			//Matrix with random values
		~Matrix(void);


		//Getters
		std::vector<int> getRow(int i);
		std::vector<int> getCol(int i);
		int getRowNum(void);
		int getColNum(void);
		std::vector<int> &get_rawData(void);	

		//Setters
		void setRowNum(int num);
		void setColNum(int num);

		//Utility funcs
		int &operator [](int i); 			//Returns a specific part of data
		void shrink_to_fit(void);			//Inherits from vector class
		void push_back(int num);			//Inherits from vector class

		/*
		For matrix algebra I used:

		https://en.wikipedia.org/wiki/Matrix_(mathematics)
		*/
		
		void operator =(Matrix other);		//Assign to the matrix other one
		friend std::ostream& operator <<(std::ostream& output, Matrix& obj);
		Matrix operator +(Matrix other);	//Add to matrix another matrix
		Matrix operator -(Matrix other);	//Subtract from matrix another matrix
		Matrix operator *(Matrix other);	//Multiply matrix by matrix, give back new matrix
		void operator *(int var);			//Multiply matrix by a scalar 
		void operator +=(Matrix other);		//Add to the current matrix other one
		void operator -=(Matrix other);		//Subtract from matrix other one
		void operator *=(Matrix other);		//Multiply matrix by the other one
		
};


//Definitions

Matrix::Matrix(void){
	rows = cols = 0;

	data.shrink_to_fit();
}


Matrix::Matrix(Matrix &other){
	//Clear matrix
	data.clear();

	rows = other.getRowNum();
	cols = other.getColNum();

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

	for(size_t i=0; i<data.size(); i++){
		//Fill with random numbers from <0, 99>
		data.push_back(rand() % TOP_LIMIT_OF_NUMBER);
	}

	data.shrink_to_fit();
}


Matrix::~Matrix(void){

}


//Getters

std::vector<int> Matrix::getRow(int i){
	std::vector<int> result(cols);
	
	for(int j=0; j<cols; j++){
		result[j] = data[i*cols + j];
	}

	result.shrink_to_fit();
	return result;
}


std::vector<int> Matrix::getCol(int j){
	std::vector<int> result(rows);
	
	for(int i=0; i<rows; i++){
		result[i] = data[i*cols + j];
	}

	result.shrink_to_fit();
	return result;
}

	
int Matrix::getRowNum(void){
	return rows;
}

int Matrix::getColNum(void){
	return cols;
}

std::vector<int> &Matrix::get_rawData(void){
	return data;
}


//Setters
void Matrix::setRowNum(int num){
	rows = num;
}

void Matrix::setColNum(int num){
	cols = num;
}


//Utility funcs
int &Matrix::operator [](int i){
	return data[i];
}


void Matrix::shrink_to_fit(void){
	data.shrink_to_fit();
}


void Matrix::push_back(int num){
	data.push_back(num);
}


//Functions
void Matrix::operator =(Matrix other){
	data.clear();	

	rows = other.getRowNum();
	cols = other.getColNum();

	data = other.get_rawData();

	data.shrink_to_fit();
}

std::ostream& operator <<(std::ostream& output, Matrix& obj){
	for(int i=0; i<obj.getRowNum(); i++){
		for(int j=0; j<obj.getColNum(); j++){
			output << std::to_string(obj[i*obj.getColNum() + j]) + ", ";
		}
		
		output << "\n";	
	}

	return output;
}


Matrix Matrix::operator +(Matrix other){
	Matrix result;

	if(rows == other.getRowNum() and cols == other.getColNum()){
		//Add element to element
		for(size_t i=0; i<data.size(); i++){
			result.push_back(data[i] + other[i]);
		}		
	}else{
		//Unable to add matrices
	}

	result.shrink_to_fit();
	return result;	
}


Matrix Matrix::operator -(Matrix other){
	Matrix result;

	if(rows == other.getRowNum() and cols == other.getColNum()){
		//Subtract element from element
		for(size_t i=0; i<data.size(); i++){
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

	if(cols == other.getRowNum()){
		result.setRowNum(rows);
		result.setColNum(other.getColNum());		

		//Add element to element
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				for(int k=0; k<other.getRowNum(); k++){
					result[i*other.getColNum() + k] += data[i*cols + j] * other[j*other.getColNum() + k];
				}	
			}
		}		
	}else{
		//Unable to multiply matrices
	}

	result.shrink_to_fit();
	return result;	
}


void Matrix::operator *(int var){
	for(size_t i=0; i<data.size(); i++){
		data[i] *= var;
	}
}


void Matrix::operator +=(Matrix other){
	if(rows == other.getRowNum() and cols == other.getColNum()){
		//Add to this matrix

		for(size_t i=0; i<data.size(); i++){
			data[i] += other[i];
		}

	}else{
		//Do nothing
	}
}


void Matrix::operator -=(Matrix other){
	if(rows == other.getRowNum() and cols == other.getColNum()){
		//Subtract from this matrix

		for(size_t i=0; i<data.size(); i++){
			data[i] -= other[i];
		}

	}else{
		//Do nothing
	}

}


void Matrix::operator *=(Matrix other){
	Matrix result(rows, other.getColNum());

	if(cols == other.getRowNum()){
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				for(int k=0; k<other.getRowNum(); k++){
					result[i*other.getColNum() + k] += this->data[i*cols + j] * other[j*other.getColNum() + k];
				}	
			}
		}		
	}else{
		//Unable to multiply matrices
	}

	this->data.swap(result.get_rawData());
	this->data.shrink_to_fit();
	this->setColNum(other.getColNum());
}
