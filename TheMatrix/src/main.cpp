#include <iostream>
#include <conio.h>
#include "TMatrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������ ������ 1 � 2: "<< endl;
	cin >> n;
	TMatrix<float> a(n), b(n), c(n);
	cout << "������� ������� 1: " << endl; 
	cin >> a;
	cout << "������� ������� 2: " << endl;
	cin >> b;
	cout << endl << "������� 1: " << endl << a << endl;
	cout << "������� 2: " << endl << b << endl;
	c = a + b;
	cout << "����� ������: " << endl << c << endl;
	c = a - b;
	cout << "�������� ������:" << endl << c << endl;
	c = a*b;
	cout << "������������ ������: " << endl << c << endl;
	cout << "C�������� ������: " << endl;
	
	if (a == b)   
	cout << "������� �����"<<endl;
	
	if (a!=b)
	cout << "������� �� �����"<<endl;

	cout << "�������"<<endl;
	c=a/b;
	cout << "��������� �������"<<endl;
	cout<<c<<endl;

	cout<<"����� �������� � 1 �������: "<<a.Sum();
	

	_getch();
	return 0;
}