#pragma once
#include <iostream>

using namespace std;

template <class T>
class TVector
{
protected:
	
	T *pVector;
	int Size;
	int StartIndex;
public:
	TVector (int s=10, int s_i=0)
	{
		pVector = new T[s];
		Size = s;
		StartIndex = s_i;
	}

	TVector(const TVector<T> &v)
	{
		pVector = new T[v.Size];
			Size = v.Size;
		StartIndex = v.StartIndex;

		for (int i(0); i < Size; i++) pVector[i] = v.pVector[i];
	}

	~TVector()
	{
		delete[] pVector;
	}

	int GetSize() { return Size; }
	int GetStartIndex() { return StartIndex; }
	T & operator[](int pos)
	{
		return pVector[pos - StartIndex];
	}

	bool operator== (const TVector &v)
	{
		bool res = true;
		if (this != &v)
		{
			if (Size != v.Size) res = false;
			else

			{
				
				for (int i(0); i < Size; i++)
				{
					if (pVector[i] != v.pVector[i]) res = false;
				
				}
			}
		}
		return res;
	}

	bool operator!= (const TVector &v)
	{
	return !operator==(v);
	}

	TVector & operator=(const TVector &v)
	{
		if (this != &v)
		{
			if (Size != v.Size)
			{
				delete[]pVector;
				pVector = new T[v.Size];
			}
			Size = v.Size;
			StartIndex = v.StartIndex;
			for (int i(0); i < Size; i++) pVector[i] = v.pVector[i];
		}
		return *this;
	}

	

	TVector operator+ (const T&val)
	{
		TVector temp(Size, StartIndex);
		for (int i(0); i < Size; i++) temp.pVector[i] += val;
		return temp;
	}
	TVector operator- (const T&val)
	{
		TVector temp(Size, StartIndex);
		for (int i(0); i < Size; i++) temp.pVector[i] -= val;
		return temp;
	}

	TVector operator* (const T&val)
	{
		TVector temp(Size, StartIndex);
		for (int i(0); i < Size; i++) temp.pVector[i] *= val;
		return temp;
	}

	TVector operator+(const TVector<T> &v)
	{
		TVector temp(Size, StartIndex);
		for (int i(0); i < Size; i++) temp.pVector[i] = pVector[i] + v.pVector[i];
		return temp;
	}

	TVector operator-(const TVector<T> &v)
	{
		TVector temp(Size, StartIndex);
		for (int i(0); i < Size; i++) temp.pVector[i] = pVector[i] - v.pVector[i];
		return temp;
	}

	TVector operator*(const TVector<T> &v)
	{

		TVector temp(Size, StartIndex);
		for (int i(0); i < Size; i++) temp.pVector[i] = pVector[i] * v.pVector[i];
		return temp;
	}


	friend istream & operator>> (istream &in, TVector<T> &v)
	{
		for (int i(0); i < v.Size; i++) in >> v.pVector[i];
		return in;
	}
	friend ostream & operator<< (ostream &out, const TVector<T> &v)
	{
		for (int i(0); i < v.Size; i++) out << v.pVector[i] << setw(4);
		return out;
	}


};
	