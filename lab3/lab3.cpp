// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//указатель(pointer) - переменная, хранящая адрес(смещение) каких-либо данных, переменных в оперативной памяти.

//1.СИНТАКСИС
//указатель объявляется как обычная переменная, но добавляется звёздочка 
//"тип_данных" * "имя_указателя (int * ptr_a);"

//фактически указатель - это unsigned int или insigned long long c адресом, 
//так как дробных или отрицательных адрессов нет
//ptr_a = &a;унарный оператор & амперсенl - оператор получения адреса 

//2.РАЗМЕР УКАЗАТЕЛЯ
// все указатели всегда одной и той разрядности(размера)
// каким бы ни был огромным тип данных (строка, объект, массив)
// указатель на него всегда будет занимать 4/8 байт, что и является основным
//преимуществом указателей 
//в случае сборки на х64 размер указателей будет 8 бaйт (64-разрядная адресация)

//3.СОДЕРЖИМОЕ УКАЗАТЕЛЯ
//имя_ указателя

#include "pch.h"
#include <iostream>

int main()
{
		int arr1D[10] = { 1, 50, 11, 12, 101 };
		int b;
		double dbl;
		int * ptr_int = &b;
		double * ptr_double = &dbl;
	
		std::cout << "int pointer size = " << sizeof(ptr_int) << std::endl;
		std::cout << "double pointer size = " << sizeof(ptr_double) << std::endl;
		std::cout << "char pointer size = " << sizeof(char *) << std::endl;
		std::cout << "long long pointer size = " << sizeof(long long *) << std::endl;
		std::cout << "bool pointer size = " << sizeof(bool *) << std::endl;
		
		std::cout << "arr = " << arr1D << std::endl;
		std::cout << "*arr = arr[0] " << *arr1D << std::endl;
		std::cout << "*(arr1D+4) = arr[4] = " << *(arr1D+4) << std::endl;

		//выход за границы допустимой памяти i+-10000
}


