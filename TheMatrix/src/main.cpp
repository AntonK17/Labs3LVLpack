#include <iostream>
#include <conio.h>
#include "TMatrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Размер матриц 1 и 2: "<< endl;
	cin >> n;
	TMatrix<float> a(n), b(n), c(n);
	cout << "Введите матрицу 1: " << endl; 
	cin >> a;
	cout << "Введите матрицу 2: " << endl;
	cin >> b;
	cout << endl << "Матрица 1: " << endl << a << endl;
	cout << "Матрица 2: " << endl << b << endl;
	c = a + b;
	cout << "Сумма Матриц: " << endl << c << endl;
	c = a - b;
	cout << "Разность Матриц:" << endl << c << endl;
	c = a*b;
	cout << "Произведение Матриц: " << endl << c << endl;
	cout << "Cравнение Матриц: " << endl;
	
	if (a == b)   
	cout << "Матрицы равны"<<endl;
	
	if (a!=b)
	cout << "Матрицы не равны"<<endl;

	cout << "Деление"<<endl;
	c=a/b;
	cout << "Результат деления"<<endl;
	cout<<c<<endl;

	cout<<"Сумма нечетных в 1 матрице: "<<a.Sum();
	

	_getch();
	return 0;
}