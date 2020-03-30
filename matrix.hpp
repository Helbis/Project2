class Matrix{
	private:
		int cols, rows;					//Number of rows & columns
		std::vector<int> data;			//Data accessed with [i][j] where it's actually (i*cols + j)

	public:
		Matrix(void);					//Matrix 0x0 -> NULL
		Matrix(Matrix other);			//Matrix copied from other
		Matrix(int r, int c);			//Matrix with random values
		~Matrix(void);

		operator =(Matrix other);		//Assign to the matrix other one
		operator <<(void);				//Print matrix row by row
		operator +(Matrix other);		//Add to matrix another matrix
		operator -(Matrix other);		//Subtract from matrix another matrix
		operator *(Matrix other);		//Multiply matrix by matrix, give back new matrix
		operator *(int var);			//Multiply matrix by a scalar 
		operator +=(Matrix other);		//Add to the current matrix other one
		operator -=(Matrix other);		//Subtract from matrix other one
		operator *=(Matrix other);		//Multiply matrix by the other one
		
};
