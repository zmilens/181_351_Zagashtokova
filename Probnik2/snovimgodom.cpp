
#include "stroki.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	MyString s("Moscow");
	cout << s << endl;

	s.clear();
	cout << s << endl;

	s.add("MoscowCity");
	cout << s << endl;
	
	s.insert(" - ", 6);
	cout << s << endl;

	s.cut(6, 3);
	cout << s << endl;

	MyString s2(", Russia");

	MyString s3 = s + s2;
	cout << s3 << endl;
	
	unsigned char *key = new unsigned char[256];
	key = (unsigned char *)"01234567890123456789012345678901"; // 256 ������ ����

	unsigned char *iv = new unsigned char[128];
	iv = (unsigned char *)"0123456789012345"; // 128 ������ �����������

	int cr_len; // ����� �����

	unsigned char* cr = s.encrypt(key, iv, &cr_len); // �������� ����
	s.decrypt(cr, cr_len, key, iv); // ���������

	s.save("1.txt"); // ��������� ������ � ����
	s.load("2.txt"); // ��������� ������ �� �����

	system("pause");

	return 0;
}
