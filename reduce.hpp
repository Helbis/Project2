#ifndef REDUCE_HPP
#define REDUCE_HPP


template<typename T=int>
class Reduce : MatrixT<T>{
	public:
		Reduce(void) : MatrixT<T>(){ this->f(); } 
		Reduce(Reduce<T> &other) : MatrixT<T>(other){ this->f(); } 
		Reduce(size_t r, size_t c) : MatrixT<T>(r, c){ this->f(); }
		Reduce(size_t r, size_t c, std::valarray<T> va) : MatrixT<T>(r, c, va){ this->f(); }
		~Reduce(void){ /* Empty */ }


		//Function to override
		void f(void) override { this->apply(Reduce::reduceNum); }

		
		//Original functions	
		bool isAlright(T num){ return ((num <= 9) and (num >= -9)); }
		T reduceNum(T num);
};


template<typename T>
T Reduce<T>::reduceNum(T num){
	std::string str;
	std::valarray<T> va;

	while(not Reduce::isAlright(num)){
		str = std::to_string(num);
		va.resize(str.size());
		
		for(size_t i=0; i<str.size(); i++){
			va[i] = boost::lexical_cast<T>(str[i]);
		}
		
		num = va.sum();	
	}

	return num;
}



#endif
