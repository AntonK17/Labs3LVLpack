#include "TAVLTree.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	AVLTree tree;

	for (int i=0;i<7;i++)

	tree.AVLAdd(i, rand()%100);

	cout << "������:" << endl;
	tree.print();

	cout << "����� �������� �� ����� 5:" << endl;
	cout << tree.findElem(5)<<endl;
	
	cout << "�������� �� ����� 3:" << endl;
	tree.del(3);
	cout << "�������� �� ����� 2:" << endl;
	tree.del(2);
	cout << "������:" << endl;
	tree.print();

	tree.RandomMatrix(5);


	_getch();
	return 0;
}