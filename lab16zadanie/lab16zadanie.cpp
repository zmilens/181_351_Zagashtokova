// lab16zadanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
template<class T>
class tree {
	struct N {
		T     item;
		N *child;
		N *brother;
		N(T i, N*s = NULL, N *b = NULL)
		{
			item = i;
			child = s;
			brother = b;
		}
		N() {};
	};

	N*root;

private:
	N*  tr;
	size_t cnt;
public:
	tree() { root = NULL; }
	void add(const T &elem)
	{
		add(root, elem);
	}

	void f()
	{
		N *temp = new N;
		*temp = *root;
		std::cout << temp->item;
		f(temp);
		*temp = *root;
		*temp = *temp->child;
		f(temp);
	}
	
private:
	void add(N *&node, const T &item)
	{
		int a;
		if (node == NULL)
		{
			node = new N(item);
		}
		else {
			std::cin >> a;
			if (/*item < node->item*/a > 0) {
				add(node->child, item);
			}

			else {
				add(node->brother, item);
			}
		}
	}
	void f(N *&node)
	{
		if (node->child != NULL)
		{
			*node = *node->child;
			std::cout << node->item;
			while (node->brother != NULL)
			{
				*node = *node->brother;
				std::cout << node->item;
			}

			*node = *root;
			*node = *node->child;
		}

	}
};
int main() {

	tree<int> t1;
	for (int i = 1; i <= 5; i++)t1.add(i);

	t1.f();
	system("pause");
	return 0;
}
