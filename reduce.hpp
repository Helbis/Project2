#ifndef REDUCE_HPP
#define REDUCE_HPP


template<typename T=int>
class Reduce : public MatrixT<T>{
	public:
		Reduce(void) : MatrixT<T>(){ this->f(); } 
		Reduce(Reduce<T> &other) : MatrixT<T>(other){ this->f(); } 
		Reduce(size_t r, size_t c) : MatrixT<T>(r, c){ this->f(); }
		Reduce(size_t r, size_t c, std::valarray<T> va) : MatrixT<T>(r, c, va){ this->f(); }
		~Reduce(void){ /* Empty */ }


		//Function to override
		void f(void) override { this->setData(this->get_rawData().apply(*(Reduce::reduceNum))); }

		
		//Original functions	
		static bool isAlright(T num){ return ((num >= (T)-9) and (num <= (T)9)); }
		static T reduceNum(T num);
};


template<typename T>
T Reduce<T>::reduceNum(T num){
	std::string str;
	std::valarray<T> va;
	str = std::to_string(num);
	
	bool negative = str[0] == '-';

	while(not Reduce::isAlright(num)){
		str = std::to_string(num);
		va.resize(str.size());

		for(size_t i=0; i<str.size(); i++){
			if(isdigit(str[i])){
				va[i] = (T)(str[i] - '0');
			}
		}		

		num = va.sum();	
	}

	return (negative ? -std::abs(num) : std::abs(num));
}

#endif
