#ifndef MATRIX_G
#define MATRIX_G


class MatrixG : public Matrix{
	public:
		MatrixG(void) : Matrix(){}
		MatrixG(MatrixG &other) : Matrix(other){}					//Matrix copied from other
		MatrixG(size_t r, size_t c);
		MatrixG(size_t r, size_t c, std::valarray<int> va);
};

MatrixG::MatrixG(size_t r, size_t c) : Matrix(r, c){
	for(size_t i=0; i<r; i++){
		for(size_t j=0; j<c; j++){
			if(!this->isEven(i+j)){
				setData(i, j, 0);
			}
		}
	}
}

MatrixG::MatrixG(size_t r, size_t c, std::valarray<int> va) : Matrix(r, c, va){
	for(size_t i=0; i<r; i++){
		for(size_t j=0; j<c; j++){
			if(!this->isEven(i+j)){
				setData(i, j, 0);
			}else{
				setData(i, j, va[i*c + j]);
			}
		}
	}
}

#endif 
