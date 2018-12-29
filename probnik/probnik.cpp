// probnik.cpp 

#include "pch.h"
#include <iostream>
#include <string>
#include "probnik.h"
int main()
{
	exam a;
	a.input();
	a.print();
	char c[4] = "443";
	//a.add(c);
	//a.cut(2,2);
	a.insert(3,c);
	a.print();
	system("pause");
	return 0;
}
exam::exam()
{
	b = new char[0];
}
exam::exam(char *b2)
{
	b = new char[strlen(b2)];
	for (int i = 0; i < strlen(b2); i++)
	{
		b[i] = b2[i];
	}
}
exam::exam(std::string &s) {}
exam::~exam(){}

void exam::clear()
{
	b = nullptr;
	l = 0;
}
void exam::add(char *b2)
{
	char *a;
	int size;
	size = strlen(b2) + l;
	a = new char[size];
	for (int i = 0; i < l; i++)
	{
		a[i] = b[i];
	}
	for (int i = l; i < size; i++)
	{
		a[i] = b2[i-l];
	}
	l = size;
	b = new char[l];
	for (int i = 0; i < size; i++)
	{
		b[i] = a[i];
	}
	delete[] a;
}
void exam::insert(int p, char *b2)
{
	if (p > l)
		std::cout << "ERROR";
	else
	{
		char *a;
		l += strlen(b2);
		a = new char[l+1];
		for (int i = 0; i < p; i++)
		{
			a[i] = b[i];
		}
		a[p] = '\0';
		for (int i = p; i < p+strlen(b2); i++)
		{
			a[i] = b2[i- p];
		}
		a[p+strlen(b2)] = '\0';
		for (int i = p + strlen(b2); i < l; i++)
		{
			a[i] = b[i - strlen(b2)];
		}
		a[l] = '\0';
		b = new char[l+1];
		for (int i = 0; i < l+1; i++)
		{
			b[i] = a[i];
		}
		delete[] a;
	}
}
void exam::cut(int p, int numm)
{
	if ((p > l) || (numm > (l - p)))
		std::cout << "error";
	else
	{
		for (int i = p - 1; i < p + numm - 1; i++)
		{
			b[i] = 0;
		}
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l - 1; j++)
			{
				if (b[j + 1] == 0)
				{
					b[j + 1] = b[j];
					b[j] = 0;
				}
			}
		}
		char *a;
		l -= numm;
		a = new char[l];
		for (int i = 0; i < l; i++)
		{
			b[i] = a[i];
		}
		delete[] a;
	}
}
void exam::input()
{
	std::cout << "l=";
	std::cin >> l;
	b = new char[l];
	for (int i = 0; i < l; i++)
	{
		std::cout << "b=";
		std::cin >> b[i];
	}
}
void exam::print()
{
	for (int i = 0; i < l; i++)
	{
		std::cout << b[i] << '\t';
	}
	std::cout << '\n';
}
void exam::add(std::string s) {}
