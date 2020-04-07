#ifndef MATRIX_D
#define MATRIX_D


template<typename T=int>
class MatrixTD : public MatrixTC<T>{
	public:
		MatrixTD(void) : MatrixTC<T>(){}
		MatrixTD(size_t n);
};


template<typename T>
MatrixTD<T>::MatrixTD(size_t n) : MatrixTC<T>(n){
	for(size_t i=0; i<n; i++){
		for(size_t j=0; j<n; j++){
			if(i != j){
				this->setData(i, j, 0);
			}
		}
	}
}


#endif 
