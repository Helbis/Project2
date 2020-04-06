#ifndef MATRIX_C
#define MATRIX_C


class MatrixC : public Matrix{
	public:
		MatrixC(void) : Matrix(){}
		MatrixC(int n) : Matrix(n, n){}
};


#endif 
