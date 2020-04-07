#ifndef MATRIXT_G
#define MATRIXT_G


template<typename T=int>
class MatrixTG : public MatrixT<T>{
	public:
		MatrixTG(void) : MatrixT<T>(){}
		MatrixTG(MatrixTG &other) : MatrixT<T>(other){}					//MatrixT copied from other
		MatrixTG(size_t r, size_t c);
		MatrixTG(size_t r, size_t c, std::valarray<T> va);
};

template<typename T>
MatrixTG<T>::MatrixTG(size_t r, size_t c) : MatrixT<T>(r, c){
	for(size_t i=0; i<r; i++){
		for(size_t j=0; j<c; j++){
			if(!this->isEven(i+j)){
				this->setData(i, j, 0);
			}
		}
	}
}

template<typename T>
MatrixTG<T>::MatrixTG(size_t r, size_t c, std::valarray<T> va) : MatrixT<T>(r, c, va){
	for(size_t i=0; i<r; i++){
		for(size_t j=0; j<c; j++){
			if(this->isEven(i+j)){
				this->setData(i, j, va[i*c + j]);
			}else{
				this->setData(i, j, 0);
			}
		}
	}
}

#endif 
