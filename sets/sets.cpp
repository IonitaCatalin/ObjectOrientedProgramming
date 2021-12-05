#include "pch.h"
#include "sets.h"
#include <iostream>
using namespace std;
Multime::Multime()
{
	Count = 0;
}
Multime::~Multime()
{
}
Multime::Multime(int value)
{
	this->add(value);
}
Multime::Multime(int *lista, int size)
{
	if (size > Count)
	{
		for (int i = 0; i < Count; i++)
			Numere[i] = *(lista + i);
	}
	else
	{
		for (int i = 0; i < size; i++)
			Numere[i] = *(lista + i);
	}
}
int Multime::Max()
{
	int maxVal = Numere[0];
	for (int i = 1; i < Count; i++)
		if (maxVal < Numere[i])
			maxVal = Numere[i];
	return maxVal;
}
int Multime::Min()
{
	int minVal = Numere[0];
	for (int i = 1; i < Count; i++)
		if (minVal > Numere[i])
			minVal = Numere[i];
	return minVal;
}
int Multime::GetSize()
{
	return Count;
}
int Multime::operator[](int index)
{
	if (index > Count)
		return -1;
	else return Numere[index];
}
Multime::operator double()
{
	return Count;
}

Multime operator & (Multime& m1, Multime & m2)
{
	Multime res;
	for (int i = 0; i < m1.GetSize(); i++)
		res.add(m1[i]);
	for (int j = 0; j < m2.GetSize(); j++)
	{
		bool found = false;
		for (int k = 0; k < res.GetSize(); k++)
			if (m2[j] == res[k])
				found = true;
		if (!found)
			res.add(m2[j]);
	}
	return res;
}
void Multime::print()
{
	for (int i = 0; i < Count; i++)
		std::cout << Numere[i] << " ";
}
bool Multime::add(int value)
{
	if (this->GetSize() < 100 )
	{
		this->Numere[this->GetSize()] = value;
		Count++;
		return true;
	}
	return false;
}
void Multime::Sort(int(*compare)(int, int))
{
	bool unsorted = true;
	do
	{
		unsorted = false;
		for(int i=0;i<Count-1;i++)
			if (compare(Numere[i], Numere[i + 1])==1)
			{
				int aux = Numere[i];
				Numere[i] = Numere[i + 1];
				Numere[i + 1] = aux;
				unsorted = true;
			}

	} while (unsorted);
}
Multime operator | (Multime& m1, Multime & m2)
{
	Multime res;
	int count = 0;
	for (int i = 0; i < m1.Count; i++)
		for (int j = 0; j < m2.Count; j++)
			if (m1[i] == m2[j])
				res.add(m1[i]);
	return res;
}
bool Multime::find(int value)
{
	for (int i = 0; i < Count; i++)
		if (Numere[i] == value)
			return true;
	return false;
}