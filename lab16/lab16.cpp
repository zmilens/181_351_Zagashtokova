// lab16.cpp 
#include "pch.h"
#include <iostream>
class Exam
{
private:
	char * s; 
	int d; //длина массива
public:
	Exam() //без параметров, создаёт строку нулевой длины
	{
		s = new char[0];
	}
	Exam(char* l) //копирует содержимое из массива * char 
	{
		s = new char[strlen(l+1)];
		strcpy(s, l);
	}
	Exam(Exam & str) //копирует содержимое из массива char  
	{
		int m = strlen(str.s);
		if (m)
		{
			s = new char[m + 1];
			strcpy(s, str.s);
		}
		else
		{
			s = new char[1];
		}
	}
	void clear();
	void add();
	void insert();
	void cut();
	Exam();
};
int main()
{
	Exam a, b;
	void clear();
	void add();
	void insert();
	void cut();
	return 0;
}
Exam::Exam() {}
Exam::Exam() {}