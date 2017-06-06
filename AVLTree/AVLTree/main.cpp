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

	cout << "Дерево:" << endl;
	tree.print();

	cout << "Поиск элемента по ключу 5:" << endl;
	cout << tree.findElem(5)<<endl;
	
	cout << "Удаление по ключу 3:" << endl;
	tree.del(3);
	cout << "Удаление по ключу 2:" << endl;
	tree.del(2);
	cout << "Дерево:" << endl;
	tree.print();

	tree.RandomMatrix(5);


	_getch();
	return 0;
}