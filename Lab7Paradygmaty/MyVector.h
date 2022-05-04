#pragma once
#include <iostream>

template<typename T> class MyVector {
	//private:
public:
	static inline int obNum = 0;
	int num = obNum++;
	T* abc;
	unsigned int size;
public:
	/*MyVector() {

		this->size = 6;
		abc = new T[size];

	}
	*/
	MyVector(unsigned int size = 6) {

		this->size = size;
		this->abc = new T[size];
		//std::cout << "ConstrP " << num << " " << typeid(abc).name() <<  std::endl;

	}
	MyVector(const MyVector<T>& other) {
		//std::cout << "ConstrCpy " << num << " " << typeid(abc).name() << std::endl;
		this->size = other.lenght();
		this->abc = new T[this->size];

		for (unsigned int i = 0; i < this->size; i++) {
			this->abc[i] = other.abc[i];
		}
	}

	MyVector<T>& operator=(const MyVector<T>& other) {
		
		T* local_abc = new T[other.lenght()];
		for (unsigned int i = 0; i < other.lenght(); i++) {
			local_abc[i] = other.abc[i];
		}
		delete[] this->abc;
		this->abc = local_abc;
		this->size = other.lenght();

		return *this;
	}

	~MyVector() {
		
		//std::cout<< " Destructor " << num << " " << typeid(abc).name() << std::endl;
		delete[] abc;
		//std::cout << " Destructor End " << num << " " << typeid(abc).name() << std::endl;
	}




	T& operator[](int index) {
		return abc[index];
	}

	MyVector<T>& operator+(const MyVector<T>& other) {
		if (this->size != other.lenght()) {
			std::cout << "Error: vectors are not the same size" << std::endl;
			return *this;
		}

		MyVector<T>* temp = new MyVector<T>(this->size);
		for (unsigned int i = 0; i < this->size; i++) {
			temp->abc[i] = other.abc[i] + this->abc[i];
		}
		return *temp;
	}

	MyVector<T>& operator-(const MyVector<T>& other) {
		if (this->size != other.lenght()) {
			std::cout << "Error: vectors are not the same size" << std::endl;
			return *this;
		}

		MyVector<T>* temp = new MyVector<T>(this->size);
		for (unsigned int i = 0; i < this->size; i++) {
			temp->abc[i] = other.abc[i] - this->abc[i];
		}
		return *temp;
	}

	MyVector<T>& operator ++(int) {
		//T z = 1;
		for (unsigned int i = 0; i < this->size; i++) {
			abc[i] = abc[i] + 1;
		}
		return *this;
	}

	MyVector<T>& operator ++() {
		for (unsigned int i = 0; i < this->size; i++) {
			abc[i] = abc[i] + 1;
		}
		return *this;
	}

	MyVector<T>& operator--(int) {
		for (unsigned int i = 0; i < this->size; i++) {
			abc[i] += -1;
		}
		return *this;
	}

	MyVector<T>& operator--() {
		for (unsigned int i = 0; i < this->size; i++) {
			abc[i] += -1;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const MyVector<T>& other) {

		//std::string temp = "";
		for (unsigned int i = 0; i < other.lenght(); i++) {
			//temp += other.abc[i];
			//temp += " ";
			os << other.abc[i] << " ";
		}
		os << std::endl;
		return os;
	}

	int operator*(const MyVector<T>& other) {
		if (this->size != other.lenght()) {
			std::cout << "Error: vectors are not the same size" << std::endl;
			return -1;
		}
		int temp = 0;
		for (unsigned int i = 0; i < this->size; i++) {
			temp += abc[i] * other.abc[i];
		}
		return temp;
	}


	const T& operator[](int index) const {
		return abc[index];
	};

	unsigned int lenght() const {

		return this->size;
	}





};