template <typename T, int SIZE>
class array{
	T data_[SIZE];
	array (const array& other);
	const array& operator = (const array& other);
	public:
	array(){};
	T& operator[](int i) {return data_[i];}
	const T& get_elem (int i) const {return data_[i];}
	void set_elem(int i, const T& value) {data_[i] = value;}
	operator T*() {return data_;}      
};

int main(void){
	array<int, 50> intArray;
	intArray.set_elem(0, 2);
	int firstElem = intArray.get_elem(0);
	int* begin = intArray;
}

