#pragma once
class exam
{
private:
	int l; //длина
	char *b;
public:
	exam();
	exam(char *b2);
	exam(std::string &s);
	~exam();
	void clear();
	void add(char *b2);
	void add(std::string s);
	void insert(int p, char *b2);
	void cut(int p, int numm);
	void input();
	void print();
};
