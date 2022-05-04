#include "MyMatrix.h"
#include <iostream>



int main()
{
	MyMatrix<int> a;
	
	a[0][0] = 0;
	a[0][1] = 1;
	a[0][2] = 2;
	a[0][3] = 3;
	a[1][0] = 4;
	a[1][1] = 5;
	a[1][2] = 6;
	a[1][3] = 7;
	a[2][0] = 8;
	a[2][1] = 9;
	a[2][2] = 10;
	a[2][3] = 11;
	a[3][0] = 12;
	a[3][1] = 13;
	a[3][2] = 14;
	a[3][3] = 15;
	MyMatrix<int> b(a);
	a--;
	MyMatrix<int> c = a + b;
	std::cout << c << std::endl;
	
	MyMatrix<int> d(3, 2);
	MyMatrix<int> e(2, 3);
	
	d[0][0] = 0;
	d[0][1] = 1;
	d[1][0] = 2;
	d[1][1] = 3;
	d[2][0] = 4;
	d[2][1] = 5;
	
	
	e[0][0] = 6;
	e[0][1] = 7;
	e[0][2] = 8;
	e[1][0] = 9;
	e[1][1] = 10;
	e[1][2] = 11;
	
	std::cout << d * e;
	
	std::cout << a.determinant();
	
}