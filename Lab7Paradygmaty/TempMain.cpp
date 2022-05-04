/*
#include "MyVector.h"
#include <iostream>



int main()
{
	//	typedef MyVector::MyVector<int> a;	//default constructor
	MyVector<int> a;	//default constructor
	
	std::cout << a;		//overload <<
	{					//elements to stream
		MyVector<double> b(2);	//constructor with size argument
		std::cout << b;
	}
	MyVector<int>* z = new MyVector<int>;

	delete z;		//destructor

	
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a[5] = 6;
	std::cout << a;// << b;
	MyVector<int> c = a;	//cpy constructor =
	std::cout << c;

	MyVector<int> d(a + c);//cpy constructor and overload +
	std::cout << d;
	d = d - c;				//overload -
	std::cout << d;

	d++;		//overload postfix ++
	std::cout << d;

	++d;		//overload prefix ++
	std::cout << d;

	d--;		//overload postfix --
	std::cout << d;

	--d;		//overload prefix --
	std::cout << d;

	std::cout << d.lenght() << std::endl;//size of vector

	int x = a * a;		//scalar multiplication
	std::cout << x;
	
	
	
	//return 0;
	
}*/