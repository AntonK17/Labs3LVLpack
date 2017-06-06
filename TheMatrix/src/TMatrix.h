#pragma once

#include <iostream>
#include "TVector.h"
#include <iomanip>


template <class T> 
class TMatrix : public TVector<TVector<T>>
{
public:
	TMatrix(int s) : TVector<TVector<T>>(s)
	{
		for (int i(0); i < s; i++)
			pVector[i] = TVector<T>(s - i, i);
	}

	TMatrix (const TVector<T> &mt) : TVector<TVector<T>>(mt) {}
	TMatrix(const TVector<TVector<T>> &mt) : TVector<TVector<T>>(mt){}
	bool operator == (const TMatrix<T> &mt)
	{
		bool res = true;
		if (this != &mt)
		{
			if (Size != mt.Size) res = false;
			else

			{

				for (int i(0); i < Size; i++)
				{
					if (pVector[i] == mt.pVector[i]) res = true;
					else res = false;

				}
			}
		}
		return res;
	}

	TMatrix & operator = (const TMatrix<T> &mt)
	{
		if (this != &mt)
		{
			if (Size != mt.Size)
			{
				delete[]pVector;
				pVector = new TVector<T>[mt.Size];
			}
			for (int i(0); i < Size; i++) pVector[i] = mt.pVector[i];
		}
		return *this;
	}

	TMatrix  operator + (const TMatrix<T> &mt)
	{
		return TVector<TVector<T>>::operator+(mt); // вектор из векторов в котором хранятся данные шаблонного типа T
	}

	TMatrix  operator - (const TMatrix<T> &mt)
	{
		return TVector<TVector<T>>::operator-(mt);
	}

	TMatrix  operator * (const TMatrix<T> &mt)
	{
		
		TMatrix rez(Size);
		
		for (int i = 0; i < Size; i++)
		for (int j = i; j < Size; j++) rez.pVector[i][j] = 0;

		for (int i= 0; i < Size; i++)
		for (int j = i; j < Size; j++){
			
		for (int m = i; m <=j; m++)
			rez.pVector[i][j]+= pVector[i][m] * mt.pVector[m][j];
		}
		return rez;
	}


	friend istream & operator >> (istream &in, TMatrix &mt)
	{
		for (int i(0); i < mt.Size; i++) in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<(ostream &out, const TMatrix &mt)
	{
		
		for (int i(0); i < mt.Size; i++)
		
		{
			out << setw(4)<<mt.pVector[i] << endl;
			out << setw(4*i+4)<< " ";
		}
		
		return out;
	}


	TMatrix  operator / (const TMatrix<T> &mt)
	{
		
		TMatrix rez(Size);
		TMatrix E (Size);
		T count=0;
		T *countN;
		countN=new T[Size];
		rez=mt;
		
		for (int i = 0; i < Size; i++)
		for (int j = i; j < Size; j++)
		{
			if (i==j)
				E.pVector[i][j]=1;
			else
			E.pVector[i][j]=0;
		}

		for (int i = 0; i < Size; i++)
		
		{
		
			count=(1/rez.pVector[i][i]);

			for(int m=i;m<Size; m++)
			{
		E.pVector[i][m]=E.pVector[i][m] * count;
		rez.pVector[i][m]=rez.pVector[i][m] * count;
			}

		for (int k=0;k<i;k++)			
		countN[k]=rez.pVector[k][i];
		
		for (int j = 0; j < i; j++)
		for (int n = i; n<Size; n++)
			{

			rez.pVector[j][n]=rez.pVector[j][n] - (rez.pVector[i][n] * countN[j]);
			E.pVector[j][n]=E.pVector[j][n] - (E.pVector[i][n] * countN[j]);

			}
		}
				
		cout<<" матрица преобразования: "<<endl<<rez<<endl;
		cout<<"Обратная матрица к b: "<<endl<<E<<endl;
			return (operator*(E));
	}

	int Sum()
	{
		T s=0;
		for (int i= 0; i < Size; i++)
		for (int j = i; j < Size; j++)
		{
			T srav=pVector[i][j] / 2;
			if ((srav - (int)srav) !=0)
			s=s+pVector[i][j];
		}

		return s;

	}
};