#pragma once
#include <iostream>
class Multime
{
private:
	int Numere[100];
	int Count;
public:
	int operator[](int index);
	operator double();
	Multime();
	Multime(int value);
	Multime(int*lista, int size);
	int Max();
	bool find(int value);
	void print();
	bool add(int value);
	int Min();
	int GetSize();
	void Sort(int(*compare)(int, int));
	friend Multime operator & (Multime&m1, Multime&m2);
	friend Multime operator | (Multime&m1, Multime&m2);
	~Multime();

};

