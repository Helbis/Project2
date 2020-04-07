#ifndef MATRIX_C
#define MATRIX_C


template<typename T>
class MatrixTC : public MatrixT<T>{
	public:
		MatrixTC(void) : MatrixT<T>(){}
		MatrixTC(int n) : MatrixT<T>(n, n){}
};


#endif 
