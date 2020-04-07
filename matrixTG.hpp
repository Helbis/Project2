#ifndef MATRIXT_G
#define MATRIXT_G


class MatrixTG : public MatrixT{
	public:
		MatrixTG(void) : MatrixT(){}
		MatrixTG(MatrixTG &other) : MatrixT(other){}					//MatrixT copied from other
		MatrixTG(size_t r, size_t c);
		MatrixTG(size_t r, size_t c, std::valarray<int> va);
};

MatrixTG::MatrixTG(size_t r, size_t c) : MatrixT(r, c){
	for(size_t i=0; i<r; i++){
		for(size_t j=0; j<c; j++){
			if(!this->isEven(i+j)){
				setData(i, j, 0);
			}
		}
	}
}

MatrixTG::MatrixTG(size_t r, size_t c, std::valarray<int> va) : MatrixT(r, c, va){
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
