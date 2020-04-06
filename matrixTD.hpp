#ifndef MATRIX_D
#define MATRIX_D


class MatrixD : public MatrixC{
	public:
		MatrixD(void) : MatrixC(){}
		MatrixD(size_t n);
};


MatrixD::MatrixD(size_t n) : MatrixC(n){
	for(size_t i=0; i<n; i++){
		for(size_t j=0; j<n; j++){
			if(i != j){
				setData(i, j, 0);
			}
		}
	}
}


#endif 
