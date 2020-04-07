#ifndef MATRIX_D
#define MATRIX_D


class MatrixTD : public MatrixTC{
	public:
		MatrixTD(void) : MatrixTC(){}
		MatrixTD(size_t n);
};


MatrixTD::MatrixTD(size_t n) : MatrixTC(n){
	for(size_t i=0; i<n; i++){
		for(size_t j=0; j<n; j++){
			if(i != j){
				setData(i, j, 0);
			}
		}
	}
}


#endif 
