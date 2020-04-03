#define TOP_LIMIT_OF_NUMBER 100


class Matrix{
	private:
		int cols, rows;					//Number of rows & columns
		std::valarray<int> data;	

	public:
		Matrix(void){ rows = cols = 0; data.resize(0); }	//Matrix 0x0 -> NULL
		Matrix(Matrix &other);			//Matrix copied from other
		Matrix(int r, int c);			//Matrix with random values
		Matrix(int r, int c, std::valarray<int> va){rows=r; cols=c; data=va; }
		~Matrix(void);


		//Getters
		std::valarray<int> getRow(int i);
		std::valarray<int> getCol(int i);
		std::valarray<int> &get_rawData(void){ return data; }
		int getRowNum(void){ return rows; }
		int getColNum(void){ return cols; }
		size_t get_rawSize(void){ return data.size(); }

		//Setters
		void setRowNum(int num){ rows = num; }
		void setColNum(int num){ cols = num; }
		void resize(int num){ data.resize(num); }
		void resize(int r, int c){ data.resize(r*c); rows=r; cols=c; }


		/*
		For matrix algebra I used:
		https://en.wikipedia.org/wiki/Matrix_(mathematics)
		*/
		
		//Operator overloading
		void operator =(Matrix other);		//Assign to the matrix other one
		void operator =(std::valarray<int> va){ data.resize(va.size()); data = va; }	
		int &operator [](int i){ return data[i]; }	
		int &operator ()(int i, int j){ return data[i*cols + j]; }	
		Matrix operator +(Matrix other);	//Add to matrix another matrix
		Matrix operator -(Matrix other);	//Subtract from matrix another matrix
		Matrix operator *(Matrix other);	//Multiply matrix by matrix, give back new matrix
		void operator *(int var){ data *= var; }	//Multiply matrix by a scalar 
		void operator +=(Matrix other){ data += other.get_rawData(); }		//Add to the current matrix other one
		void operator -=(Matrix other){ data -= other.get_rawData(); }		//Subtract from matrix other one
		void operator *=(Matrix other);		//Multiply matrix by the other one

		
		//Some funcs from valarray
		//Matrix apply(int func(int)){ return Matrix(this->rows, this->cols, data.apply(func)); }
		

		//Math fanctions from valarray
		void abs(void){ std::abs(data); }
		//Power funcs
		void exp(void){ std::exp(data); }
		void log(void){ std::log(data); }
		void log10(void){ std::log10(data); }
		void pow(int exp){ std::pow(data, exp); }
		void pow(std::valarray<int> va_exp){ std::pow(data, va_exp); }
		void sqrt(void){ std::sqrt(data); }
		//Trig funcs
		void sin(void){ std::sin(data); }
		void cos(void){ std::cos(data); }
		void tan(void){ std::tan(data); }
		void asin(void){ std::asin(data); }
		void acos(void){ std::acos(data); }
		void atan(void){ std::atan(data); }
		void atan2(std::valarray<int> va){ std::atan2(data, va); }
		void sinh(void){ std::sinh(data); }
		void cosh(void){ std::cosh(data); }
		void tanh(void){ std::tanh(data); }
			

		//Friends of Matrix
		friend std::ostream& operator <<(std::ostream& output, Matrix& obj);
};


//Definitions
Matrix::Matrix(Matrix &other){
	data.resize(other.get_rawSize()); //Clear data

	rows = other.getRowNum();
	cols = other.getColNum();
	data = other.get_rawData();
}


Matrix::Matrix(int r, int c){
	rows = r;
	cols = c;
	data.resize(r, c);

	srand(time(NULL));	// initialize random seed

	for(size_t i=0; i<data.size(); i++){
		//Fill with random numbers from <0, 99>
		data[i] = rand() % TOP_LIMIT_OF_NUMBER;
	}
}


Matrix::~Matrix(void){

}


//Getters
std::valarray<int> Matrix::getRow(int i){
	std::valarray<int> result(cols);
	
	for(int j=0; j<cols; j++){
		result[j] = data[i*cols + j];
	}

	return result;
}


std::valarray<int> Matrix::getCol(int j){
	std::valarray<int> result(rows);
	
	for(int i=0; i<rows; i++){
		result[i] = data[i*cols + j];
	}
	
	return result;
}


//Setters


//Functions
void Matrix::operator =(Matrix other){
	data.resize(other.get_rawSize());	

	rows = other.getRowNum();
	cols = other.getColNum();
	data = other.get_rawData();
}


Matrix Matrix::operator +(Matrix other){
	Matrix result;

	if(rows == other.getRowNum() and cols == other.getColNum()){
		//Add element to element
		result = this->data + other.get_rawData();	
	}else{
		//Unable to add matrices
	}

	return result;	
}


Matrix Matrix::operator -(Matrix other){
	Matrix result;

	if(rows == other.getRowNum() and cols == other.getColNum()){
		//Subtract element from element
		result = this->data - other.get_rawData();	
	}else{
		//Unable to subtract matrices
	}

	return result;	
}


Matrix Matrix::operator *(Matrix other){
	Matrix result;

	if(cols == other.getRowNum()){
		result.resize(rows, other.getColNum());

		for(int i=0; i<this->getRowNum(); i++){
			for(int j=0; j<other.getColNum(); j++){
				result(i, j) = (this->getRow(i) * other.getCol(j)).sum();
			}
		}
	}else{
		//Unable to multiply matrices
	}

	return result;	
}


void Matrix::operator *=(Matrix other){
	Matrix result;

	if(cols == other.getRowNum()){
		result.resize(rows, other.getColNum());

		for(int i=0; i<this->getRowNum(); i++){
			for(int j=0; j<other.getColNum(); j++){
				result(i, j) = (this->getRow(i) * other.getCol(j)).sum();
			}
		}
	}else{
		//Unable to multiply matrices
	}

	this->data.swap(result.get_rawData());
	this->setColNum(other.getColNum());
}


//Friends of matrix
std::ostream& operator <<(std::ostream& output, Matrix& obj){
	for(int i=0; i<obj.getRowNum(); i++){
		for(int j=0; j<obj.getColNum(); j++){
			output << std::to_string(obj[i*obj.getColNum() + j]) + ", ";
		}
		
		output << "\n";	
	}

	return output;
}
