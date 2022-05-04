#pragma once
#include "MyVector.h"

//nie dziedziczymy destruktorow i konstruktorow

template<typename T> class MyMatrix : public MyVector <T> {
public:
	
	unsigned int row;
	unsigned int col;
	
	MyVector<typename T>* cde;
	
	
	
	MyMatrix(unsigned int n = 4, unsigned int m = 4) 
	{
		this->row = n;
		this->col = m;
		this->cde = new MyVector<T>[n];
		
		for (unsigned int i = 0; i < n; i++)
		{
			this->cde[i] = MyVector<T>(m);
		}
	}
	
	MyMatrix(const MyMatrix<T>& mx)
	{
		this->row = mx.row;
		this->col = mx.col;
		this->cde = new MyVector<T>[mx.row];
		
		for (unsigned int i = 0; i < mx.row; i++)
		{
			this->cde[i] = MyVector<T>(mx.col);
		}
		
		for (unsigned int i = 0; i < mx.row; i++)
		{
			for (unsigned int j = 0; j < mx.col; j++)
			{
				this->cde[i][j] = mx.cde[i][j];
			}
		}
	}
	
	MyMatrix<T>& operator=(const MyMatrix<T>& mx)
	{
		MyVector<T>* local_cde = new MyVector<T>(mx.row);
		for (unsigned int i = 0; i < mx.row; i++)
		{
			local_cde[i].resize(mx.col);
		}
		
		for (unsigned int i = 0; i < mx.row; i++)
		{
			for (unsigned int j = 0; j < mx.col; j++)
			{
				local_cde[i][j] = mx.cde[i][j];
			}
		}
		for (unsigned int i = 0; i < mx.row; i++)
		{
			delete[] this->cde[i];
		}
		delete[] this->cde;
		this->cde = local_cde;
		this->row = mx.row;
		this->col = mx.col;
		
		return *this;
	}
	
	
	~MyMatrix() {	//nie dziedziczymy destruktorow i konstruktorow
		/*for (unsigned int i = 0; i < this->row; i++)
		{
			std::cout << "aaaaaaaaaaaa \n";
			MyVector<T>* z = &this->cde[i];
			delete[] z->abc;
		}
		std::cout << "bbbbbbbbbbbbb \n";*/
		//**********************************************************************************************
		delete[] this->cde;		//<- to powinno byc bez petli i jestem w stanie to udowodnic!!!!!!!!
		//**********************************************************************************************
	}
	
	MyVector<T>& operator[](unsigned int i)
	{
		
		return this->cde[i];
	}
	
	bool isSquare ()
	{
		if (this->row == this->col)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	T determinant() {
		if (this->isSquare())
		{
			if (this->row == 2)
			{
				return this->cde[0][0] * this->cde[1][1] - this->cde[0][1] * this->cde[1][0];
			}
			else
			{
				T det = 0;
				T mult = 0;
				for (unsigned int i = 0; i < this->col; i++)
				{
					mult = this->cde[i][0];
					int x = i;
					int y = 0;
					
					for(unsigned int j = 0; j < this->col; j++)
					{
						x++;
						y++;
						if(x == this->col)
						{
							x = 0;
						}
						mult = mult * this->cde[x][y];
						
					}
					det = det + mult;
				}
				
				for (unsigned int i = 0; i < this->col; i++)
				{
					mult = this->cde[i][0];
					int x = i;
					int y = 0;

					for (unsigned int j = 0; j < this->col; j++)
					{
						x--;
						y++;
						if (x == -1)
						{
							x = this->col - 1;
						}
						mult = mult * this->cde[x][y];

					}
					det = det - mult;
				}
				
				return det;
			}
		}
		else
		{
			return -1;
		}
	}

	MyMatrix<T>& operator ++(int) {
		for(unsigned int i = 0; i < this->row; i++)
		{
				this->cde[i]++;
		}
		return *this;
	}

	MyMatrix<T>& operator --(int) {
		for(unsigned int i = 0; i < this->row; i++)
		{
				this->cde[i]--;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, MyMatrix<T>& mx)
	{
		for (unsigned int i = 0; i < mx.row; i++)
		{
			for (unsigned int j = 0; j < mx.col; j++)
			{
				out << mx.cde[i][j] << " ";
			}
			out << std::endl;
		}
		return out;
	}
	
	MyMatrix<T>& operator+(const MyMatrix<T>& other) {
		if(this->row == other.row && this->col == other.col)
		{
			MyMatrix<T>* local_cde = new MyMatrix<T>(this->row, this->col);
			for (unsigned int i = 0; i < this->row; i++)
			{
				
				local_cde->cde[i] = this->cde[i] + other.cde[i];
				
			}
			
			return *local_cde;
		}
		else
		{
			return *this;
		}
	}

	MyMatrix<T>& operator-(const MyMatrix<T>& other) {
		if (this->row == other.row && this->col == other.col)
		{
			MyMatrix<T>* local_cde = new MyMatrix<T>(this->row, this->col);
			for (unsigned int i = 0; i < this->row; i++)
			{

				local_cde->cde[i] = this->cde[i] - other.cde[i];

			}

			return *local_cde;
		}
		else
		{
			return *this;
		}
	}

	MyMatrix<T>& operator*(const MyMatrix<T>& other) {
		if (this->col == other.row)
		{
			MyMatrix<T>* local_cde = new MyMatrix<T>(this->row, other.col);
			for (unsigned int i = 0; i < this->row; i++)
			{
				for (unsigned int j = 0; j < other.col; j++)
				{
					local_cde->cde[i][j] = 0;
					for (unsigned int k = 0; k < this->col; k++)
					{
						local_cde->cde[i][j] += this->cde[i][k] * other.cde[k][j];
					}
				}
			}
			return *local_cde;
		}
		else
		{
			return *this;
		}
	}
	

	
};
