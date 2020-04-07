#ifndef MATRIX_C
#define MATRIX_C


class MatrixTC : public MatrixT{
	public:
		MatrixTC(void) : MatrixT(){}
		MatrixTC(int n) : MatrixT(n, n){}
};


#endif 
