#define TOP_LIMIT_OF_NUMBER 100


class Matrix{
	private:
		int cols, rows;					//Number of rows & columns
		std::valarray<int> data;	

	public:
		Matrix(void){ rows = cols = 0; }	//Matrix 0x0 -> NULL
		Matrix(Matrix &other);			//Matrix copied from other
		Matrix(int r, int c);			//Matrix with random values
		~Matrix(void);


		//Getters
		std::valarray<int> getRow(int i);
		std::valarray<int> getCol(int i);
		int getRowNum(void){ return rows; }
		int getColNum(void){ return cols; }
		std::valarray<int> &get_rawData(void){ return data; }
		size_t get_rawSize(void){ return data.size(); }

		//Setters
		void setRowNum(int num){ rows = num; }
		void setColNum(int num){ cols = num; }

		//Utility funcs
		void push_back(int num);			//Inherits from vector class

		/*
		For matrix algebra I used:

		https://en.wikipedia.org/wiki/Matrix_(mathematics)
		*/
		
		//Operator overloading
		void operator =(Matrix other);		//Assign to the matrix other one
		void operator =(std::valarray<int> va){ data.resize(va.size()); data = va; }	
		int &operator [](int i){ return data[i]; }	
		Matrix operator +(Matrix other);	//Add to matrix another matrix
		Matrix operator -(Matrix other);	//Subtract from matrix another matrix
		Matrix operator *(Matrix other);	//Multiply matrix by matrix, give back new matrix
		void operator *(int var){ data *= var; }	//Multiply matrix by a scalar 
		void operator +=(Matrix other){ data += other.get_rawData(); }		//Add to the current matrix other one
		void operator -=(Matrix other){ data -= other.get_rawData(); }		//Subtract from matrix other one
		void operator *=(Matrix other);		//Multiply matrix by the other one
	

		//Friends of Matrix
		friend std::ostream& operator <<(std::ostream& output, Matrix& obj);
};


//Definitions
Matrix::Matrix(Matrix &other){
	//Clear matrix
	data.resize(other.get_rawSize());

	rows = other.getRowNum();
	cols = other.getColNum();
	
	data = other.get_rawData();
}


Matrix::Matrix(int r, int c){
	rows = r;
	cols = c;
	data.resize(r * c);

	/* initialize random seed: */
	srand(time(NULL));	

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


//Utility funcs


//Functions
void Matrix::operator =(Matrix other){
	data.resize(other.get_rawSize());	

	rows = other.getRowNum();
	cols = other.getColNum();

	data = other.get_rawData();
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

	return result;	
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
	this->setColNum(other.getColNum());
}
