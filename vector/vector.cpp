// vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "stdafx.h"
#include <iostream>


using namespace std;

class Vectors : public Matrix
{
private:

	int l1 = 1;
	int l2;
	int ** B1;

public:
	//Vectors(int **B1, int g1);

	//Vectors();

	void VECTOR_RESULT(Vectors B1, Vectors B2, Vectors B);

	//~Vectors();
};
Matrix operator + (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);
	return result.SUM(lhs, rhs);
}

Matrix operator - (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);

	return result.SUBSTRACTION(lhs, rhs);

}

Matrix operator * (Matrix lhs,
	Matrix rhs)
{
	Matrix result(1, 1);

	return result.MULTIPLY(lhs, rhs);
}

ostream & operator << (ostream & os,
	Matrix & rhs)
{
	rhs.vyvod(rhs);
	return os;
}

int main()
{
	Matrix obj1;
	Matrix obj2;

	for (int i = 0; i < obj1.ll1; i++)
	{
		for (int j = 0; j < obj1.ll2; j++)
		{
			obj1.A[i][j] = 2;
		}
	}
	for (int i = 0; i < obj2.ll1; i++)
	{
		for (int j = 0; j < obj2.ll2; j++)
		{
			obj2.A[i][j] = 4;
		}
	}
	cout << "MULTIPLY" << (obj1 * obj2);
	cout << "SUM" << (obj1 + obj2);
	cout << "SUBSTRACTION" << (obj1 - obj2);
	system("pause");
	return 0;
}
