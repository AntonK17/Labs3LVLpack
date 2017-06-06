#include <iostream>
using namespace std;

typedef int Type;

struct AVL
{
	int data;
	int height;
	Type key;
	AVL* right;
	AVL* left;
	AVL(Type k, int d)
	
	{ 
		data= d;
		key= k; 
		height= 1; 
		left=right = 0; 
	}
};

class AVLTree

{	
private:

int* mas;
AVL* root;

int AVLHeight(AVL* tree)
	{
	return tree ? tree->height : 0;
	}

int GetBalance(AVL* tree)
	{
	return AVLHeight(tree->right) - AVLHeight(tree->left);
	}

void HeightBalance(AVL* tree)
	
	{

	int RHeight = AVLHeight(tree->right);
	int LHeight = AVLHeight(tree->left);
	tree->height = (LHeight>RHeight ? LHeight : RHeight) + 1;

	}

AVL* AVLAdd(AVL* tree, Type k, int d)

	{
	if (!tree) return new AVL(k,d);
	if (k<tree->key)
		tree->left = AVLAdd(tree->left, k,d);
	else
		tree->right = AVLAdd(tree->right, k,d);
	return Balance(tree);
	}

AVL* RotateLeft(AVL* a)
	{
	AVL* b = a->right;
	a->right = b->left;
	b->left = a;

	HeightBalance(a);
	HeightBalance(b);

	return b;
	}


AVL* RotateRight (AVL* b)
	{
	AVL* a = b->left;
	b->left = a->right;
	a->right = b;

	HeightBalance(b);
	HeightBalance(a);

	return a;
	}


AVL* Balance(AVL* tree)
	{
	HeightBalance(tree);
	if (GetBalance(tree) == 2)
		{

		if (GetBalance(tree->right) < 0)
			tree->right = RotateRight (tree->right);
		return RotateLeft(tree);

		}
	if (GetBalance(tree) == -2)
		{

		if (GetBalance(tree->left) > 0)
			tree->left = RotateLeft(tree->left);
		return RotateRight (tree);
		}
	return tree;
	}

AVL* DeleteElem(AVL* tree, Type k)

	{

	if (!tree) return 0;
	if (k < tree->key)
		tree->left = DeleteElem(tree->left, k);
	else if (k > tree->key)
		tree->right = DeleteElem(tree->right, k);
	else 
		{
		AVL* a = tree->left;
		AVL* b = tree->right;
		delete tree;
		if (!b) return a;
		AVL* min = Findmin(b);
		min->right = Deletemin(b);
		min->left = a;
		return Balance(min);
		}
	return Balance(tree);
	}

AVL *find(AVL*tree, Type k)

	{
	if (!tree)
		return NULL;
	else if (k == tree->key)
		return tree;
	else if (k<tree->key)
		tree->left = find(tree->left, k);
	else if (k > tree->key)
		tree->right = find(tree->right, k);
	}

AVL* Findmin(AVL* tree)
	{
	return tree->left ? Findmin(tree->left) : tree;
	}

AVL* Deletemin(AVL* tree)

	{
	if (tree->left == 0)
		return tree->right;
	tree->left = Deletemin(tree->left);
	return Balance(tree);

	}


void  PrintAVL(AVL *tree, int level)
	{
	if (tree->left)
		PrintAVL(tree->left, level + 1);
	cout<<"("<<tree->key<<") Ключ:"<<tree->data<<endl;
	if(tree->right)
		PrintAVL(tree->right, level + 1);
	
	}

int Getmatrix(AVL*tree, int level)
	{
	

	mas[q]=tree->data;
	q=q+1;

		if (tree->left)
	Getmatrix(tree->left, level + 1);

		if(tree->right)
	Getmatrix(tree->right, level + 1);
		
		return tree->data;

	}

public:

	int q;
	AVLTree() :root(0), q(0)
	{};

void AVLAdd(Type k, int d)
	{
	root = AVLAdd(root, k,d);
	}

Type findElem(Type key)

	{
	AVL* tmp = find(root, key);
	return tmp ? tmp->data :NULL;
	}

void del(Type key)
	{
	if (key!=root->key) 
	DeleteElem(root, key);
	else cout << "Корень нельзя удалить"<< endl;
	}

void print()
	{
	cout<<"Корень:("<<root->key<<";"<<root->data<<");"<<endl;
	PrintAVL(root, 0);
	}

void RandomMatrix(int size)
{
	mas=new int[size];
	int k=0,r=0;
	Getmatrix(root,0);
	int sum=(((1+(size-1))*(size-1))/2);
	cout<<"random (Element, indexInMatrix): "<<endl;
	while(k!=sum)
	{
		r=rand()%size;
		if (mas[r] != -1)
		{
			cout<<"("<< mas[r]<<", "<<r<<")";
			mas[r]=-1;
			k=k+r;
		}
	}

}

};
