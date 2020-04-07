#ifndef MATRIXT_HPP
#define MATRIXT_HPP

#define TOP_LIMIT_OF_NUMBER 100


enum commands : int{
	CLEAR
};


template<typename T=int>
class MatrixT{
	private:
		size_t cols, rows;					//Number of rows & columns
		std::valarray<T> data;	

	public:
		MatrixT<T>(void){ this->resize(0, 0); }		//MatrixT 0x0 -> NULL
		MatrixT<T>(MatrixT<T> &other);					//MatrixT copied from other
		MatrixT<T>(size_t r, size_t c);				//MatrixT with random values
		MatrixT<T>(size_t r, size_t c, std::valarray<T> va){ this->resize(r, c); this->data=va; }
		~MatrixT(void){ /* Empty */ }


		//Getters
		std::valarray<T> getRow(size_t i);
		std::valarray<T> getCol(size_t i);
		std::valarray<T> &get_rawData(void){ return this->data; }
		size_t getRowNum(void){ return this->rows; }
		size_t getColNum(void){ return this->cols; }
		size_t get_rawSize(void){ return this->data.size(); }

		//Setters
		void setRowNum(size_t num){ this->rows = num; }
		void setColNum(size_t num){ this->cols = num; }
		void setData(int COMMAND);								//Set data with specific command
		void setData(size_t i, size_t j, T d){ this->data[i*this->cols + j] = d; }	//Set data to specific value
		void setData(std::valarray<T> va){ this->data = va; }		//Set data to given valarray
		void resize(size_t r, size_t c){ this->data.resize(r*c); this->rows=r; this->cols=c; }


		/*
		For matrix algebra I used:
		https://en.wikipedia.org/wiki/MatrixT_(mathematics)
		*/
		
		//Operator overloading
		void operator =(MatrixT<T> other);		//Assign to the matrix other one
		void operator =(std::valarray<T> va){ this->resize(va.size()); this->setData(va); }	
		T &operator [](size_t i){ return this->data[i]; }	
		T &operator ()(size_t i, size_t j){ return this->data[i*this->cols + j]; }	
		MatrixT operator +(MatrixT<T> other);	//Add to matrix another matrix
		MatrixT operator -(MatrixT<T> other);	//Subtract from matrix another matrix
		MatrixT operator *(MatrixT<T> other);	//Multiply matrix by matrix, give back new matrix
		void operator *(T var){ this->data *= var; }	//Multiply matrix by a scalar 
		void operator +=(MatrixT<T> other){ this->data += other.get_rawData(); }		//Add to the current matrix other one
		void operator -=(MatrixT<T> other){ this->data -= other.get_rawData(); }		//Subtract from matrix other one
		void operator *=(MatrixT<T> other);		//Multiply matrix by the other one
		void transpose(void);		
		

		//Math fanctions from valarray
		void abs(void){ std::abs(this->data); }
		//Power funcs
		void exp(void){ std::exp(this->data); }
		void log(void){ std::log(this->data); }
		void log10(void){ std::log10(this->data); }
		void pow(T exp){ std::pow(this->data, exp); }
		void pow(std::valarray<T> va_exp){ std::pow(this->data, va_exp); }
		void sqrt(void){ std::sqrt(this->data); }
		//Trig funcs
		void sin(void){ std::sin(this->data); }
		void cos(void){ std::cos(this->data); }
		void tan(void){ std::tan(this->data); }
		void asin(void){ std::asin(this->data); }
		void acos(void){ std::acos(this->data); }
		void atan(void){ std::atan(this->data); }
		void atan2(std::valarray<T> va){ std::atan2(this->data, va); }
		void sinh(void){ std::sinh(this->data); }
		void cosh(void){ std::cosh(this->data); }
		void tanh(void){ std::tanh(this->data); }
			

		//Friends of MatrixT
		template<typename U>
		friend std::ostream& operator <<(std::ostream& output, MatrixT<U> &obj);

		//Some additional func
		bool isEven(size_t a){ return (a % 2 == 0); }
};


//Definitions
template<typename T>
MatrixT<T>::MatrixT(MatrixT<T> &other){
	
	this->resize(other.getRowNum(), other.getColNum());
	data = other.get_rawData();
}


template<typename T>
MatrixT<T>::MatrixT(size_t r, size_t c){
	this->resize(r, c);

	srand(time(NULL));	// initialize random seed

	for(size_t i=0; i<this->get_rawSize(); i++){
		//Fill with random numbers from <0, 99>
		data[i] = rand() % TOP_LIMIT_OF_NUMBER;
	}
}


//Getters
template<typename T>
std::valarray<T> MatrixT<T>::getRow(size_t i){
	std::valarray<T> result(this->cols);
	
	for(size_t j=0; j<this->cols; j++){
		result[j] = this->data[i*this->cols + j];
	}

	return result;
}


template<typename T>
std::valarray<T> MatrixT<T>::getCol(size_t j){
	std::valarray<T> result(this->rows);
	
	for(size_t i=0; i<this->rows; i++){
		result[i] = this->data[i*this->cols + j];
	}
	
	return result;
}


//Setters
template<typename T>
void MatrixT<T>::setData(int COMMAND){
	if(COMMAND == CLEAR){
		this->resize(0, 0);
	}
}


//Functions
template<typename T>
void MatrixT<T>::operator =(MatrixT<T> other){
	this->resize(other.getRowNum(), other.getColNum());
	this->data = other.get_rawData();
}


template<typename T>
MatrixT<T> MatrixT<T>::operator +(MatrixT<T> other){
	MatrixT<T> result;

	if(this->rows == other.getRowNum() and this->cols == other.getColNum()){
		//Add element to element
		result = this->data + other.get_rawData();	
	}else{
		//Unable to add matrices
	}

	return result;	
}


template<typename T>
MatrixT<T> MatrixT<T>::operator -(MatrixT<T> other){
	MatrixT<T> result;

	if(this->rows == other.getRowNum() and this->cols == other.getColNum()){
		//Subtract element from element
		result = this->data - other.get_rawData();	
	}else{
		//Unable to subtract matrices
	}

	return result;	
}


template<typename T>
MatrixT<T> MatrixT<T>::operator *(MatrixT<T> other){
	MatrixT<T> result;

	if(this->cols == other.getRowNum()){
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


template<typename T>
void MatrixT<T>::operator *=(MatrixT<T> other){
	MatrixT<T> result;

	if(this->cols == other.getRowNum()){
		result.resize(this->rows, other.getColNum());

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

template<typename T>
void MatrixT<T>::transpose(void){
	std::valarray<T> column(this->rows);	
	std::valarray<T> trans(this->rows * this->cols);
	size_t i = 0;

	for(size_t c=0; c<this->cols; c++, i += this->rows){
		column = this->getCol(c);
		
		for(size_t s=0; s<this->rows; s++){
			trans[i+s] = column[s];
		}
	}
}


//Friends of matrix
template<typename U>
std::ostream& operator <<(std::ostream& output, MatrixT<U> &obj){
	for(size_t i=0; i<obj.getRowNum(); i++){
		for(size_t j=0; j<obj.getColNum(); j++){
			output << std::to_string(obj[i*obj.getColNum() + j]) + ", ";
		}
		
		output << "\n";	
	}

	return output;
}

#endif
