#ifndef MATRIX_HPP
#define MATRIX_HPP

#define TOP_LIMIT_OF_NUMBER 100


enum commands : int{
	CLEAR
};


class Matrix{
	private:
		size_t cols, rows;					//Number of rows & columns
		std::valarray<int> data;	

	public:
		Matrix(void){ this->resize(0, 0); }		//Matrix 0x0 -> NULL
		Matrix(Matrix &other);					//Matrix copied from other
		Matrix(size_t r, size_t c);				//Matrix with random values
		Matrix(size_t r, size_t c, std::valarray<int> va){ this->resize(r, c); data=va; }
		~Matrix(void);


		//Getters
		std::valarray<int> getRow(size_t i);
		std::valarray<int> getCol(size_t i);
		std::valarray<int> &get_rawData(void){ return data; }
		size_t getRowNum(void){ return rows; }
		size_t getColNum(void){ return cols; }
		size_t get_rawSize(void){ return data.size(); }

		//Setters
		void setRowNum(size_t num){ rows = num; }
		void setColNum(size_t num){ cols = num; }
		void setData(int COMMAND);								//Set data with specific command
		void setData(size_t i, size_t j, int d);				//Set data to specific value
		void setData(std::valarray<int> va){ data = va; }		//Set data to given valarray
		void resize(size_t num){ data.resize(num); }
		void resize(size_t r, size_t c){ data.resize(r*c); rows=r; cols=c; }


		/*
		For matrix algebra I used:
		https://en.wikipedia.org/wiki/Matrix_(mathematics)
		*/
		
		//Operator overloading
		void operator =(Matrix other);		//Assign to the matrix other one
		void operator =(std::valarray<int> va){ this->resize(va.size()); this->setData(va); }	
		int &operator [](size_t i){ return data[i]; }	
		int &operator ()(size_t i, size_t j){ return data[i*cols + j]; }	
		Matrix operator +(Matrix other);	//Add to matrix another matrix
		Matrix operator -(Matrix other);	//Subtract from matrix another matrix
		Matrix operator *(Matrix other);	//Multiply matrix by matrix, give back new matrix
		void operator *(int var){ data *= var; }	//Multiply matrix by a scalar 
		void operator +=(Matrix other){ data += other.get_rawData(); }		//Add to the current matrix other one
		void operator -=(Matrix other){ data -= other.get_rawData(); }		//Subtract from matrix other one
		void operator *=(Matrix other);		//Multiply matrix by the other one
		void transpose(void);		

		
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


		//Some additional func
		bool isEven(size_t a){ return (a % 2 == 0); }
};


//Definitions
Matrix::Matrix(Matrix &other){
	data.resize(other.get_rawSize()); //Clear data

	rows = other.getRowNum();
	cols = other.getColNum();
	data = other.get_rawData();
}


Matrix::Matrix(size_t r, size_t c){
	this->resize(r, c);

	srand(time(NULL));	// initialize random seed

	for(size_t i=0; i<data.size(); i++){
		//Fill with random numbers from <0, 99>
		data[i] = rand() % TOP_LIMIT_OF_NUMBER;
	}
}


Matrix::~Matrix(void){

}


//Getters
std::valarray<int> Matrix::getRow(size_t i){
	std::valarray<int> result(cols);
	
	for(size_t j=0; j<cols; j++){
		result[j] = data[i*cols + j];
	}

	return result;
}


std::valarray<int> Matrix::getCol(size_t j){
	std::valarray<int> result(rows);
	
	for(size_t i=0; i<rows; i++){
		result[i] = data[i*cols + j];
	}
	
	return result;
}


//Setters
void Matrix::setData(int COMMAND){
	if(COMMAND == CLEAR){
		this->resize(0);
		this->resize(0, 0);
	}
}


void Matrix::setData(size_t i, size_t j, int d){
	data[i*cols + j] = d;
}


//Functions
void Matrix::operator =(Matrix other){
	this->resize(other.getRowNum(), other.getColNum());
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

		for(size_t i=0; i<this->getRowNum(); i++){
			for(size_t j=0; j<other.getColNum(); j++){
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

		for(size_t i=0; i<this->getRowNum(); i++){
			for(size_t j=0; j<other.getColNum(); j++){
				result(i, j) = (this->getRow(i) * other.getCol(j)).sum();
			}
		}
	}else{
		//Unable to multiply matrices
	}

	this->data.swap(result.get_rawData());
	this->setColNum(other.getColNum());
}


void Matrix::transpose(void){
	std::valarray<int> column(rows);	
	std::valarray<int> trans(data.size());
	size_t i = 0;

	for(size_t c=0; c<cols; c++, i += rows){
		column = this->getCol(c);
		
		for(size_t s=0; s<rows; s++){
			trans[i+s] = column[s];
		}
	}
}


//Friends of matrix
std::ostream& operator <<(std::ostream& output, Matrix& obj){
	for(size_t i=0; i<obj.getRowNum(); i++){
		for(size_t j=0; j<obj.getColNum(); j++){
			output << std::to_string(obj[i*obj.getColNum() + j]) + ", ";
		}
		
		output << "\n";	
	}

	return output;
}

#endif
