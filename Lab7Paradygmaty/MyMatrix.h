#pragma once
#include "MyVector.h"
template<typename T> class MyMatrix : public MyVector <T>
{
public:
	
	unsigend int row;
	unsigned int col;
	
	MyVector<typename T>* cdb;
	
	
	
	MyMatrix(unsigend int n, unsigend int m) 
	{
		this->row = n;
		this->col = m;
		this->cdb = new MyVector<T>[n];
		
		for (unsigned int i = 0; i < n; i++)
		{
			this->cdb[i].resize(m);
		}
	}
	
	MyMatrix(const MyMatrix<T>& mx)
	{
		this->row = mx.row;
		this->col = mx.col;
		this->cdb = new MyVector<T>[mx.row];
		
		for (unsigned int i = 0; i < mx.row; i++)
		{
			this->cdb[i].resize(mx.col);
		}
		
		for (unsigned int i = 0; i < mx.row; i++)
		{
			for (unsigned int j = 0; j < mx.col; j++)
			{
				this->cdb[i][j] = mx.cdb[i][j];
			}
		}
	}

	MyMatrix<T>& operator=(const MyMatrix<T>& mx)
	{
		MyMatrix<typename T>* local_cdb = new MyVector<T>[mx.row];
		
		
	}
	
	
	
};
