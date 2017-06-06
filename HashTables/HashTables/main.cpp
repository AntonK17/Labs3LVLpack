#include "HashTable.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <fstream> 


using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");
	ifstream in;
	in.open("123.txt");
	int a;
	HashTable t;
	in>>a;
	t.Add(1, a);
	in>>a;
	t.Add(2, a);
	in>>a;
	t.Add(3, a);
	in>>a;
	t.Add(4, a);
	in>>a;
	t.Add(4, a);
	t.Find(1); 
	t.Find(2); 
	t.Find(3);
	t.Find(4); 

	cout << endl<<"Удаление "<< endl;
	t.Delete(1);
	cout << endl;
	t.Delete(1);
	
	cout<< endl <<"Поиск "<< endl;
	t.Find(2);
	cout << endl;
	t.Find(100);
	cout << endl;
	t.Find(1);

	getch();
	return 0;
}