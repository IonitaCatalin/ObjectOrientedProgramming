#include "pch.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;
class ListaParagrafe
{
public:
	string*text;
	int Count;
public:
	ListaParagrafe();
	//~ListaParagrafe();
	void Add(string var);
	string*begin();
	string*end();
};
class Procesator
{
public:
	virtual void Proceseaza(string str)=0;
	virtual void Print() = 0;
};
class ProcesatorNumarCuvinte :public Procesator
{
public:
	map<string, int> numarCuvinte;
public:
	void Proceseaza(string str);
	void Print();
};
class ProcesatorNumarPropozitii :public Procesator
{
private:
	int nrPropozitii;
public:
	void Proceseaza(string str);
	void Print();
};
ListaParagrafe::ListaParagrafe()
{
	text = nullptr;
	Count = 0;
}
void ListaParagrafe::Add(string var)
{
	if (text == nullptr)
	{
		Count = 1;
		text = new string[Count];
		text[0] = var;
	}
	else
	{
		string*newString = new string[Count + 1];
		for (int i = 0; i < Count; i++)
			newString[i] = text[i];
		newString[Count] = var;
		Count++;
		text = newString;
	}
}

string * ListaParagrafe::begin()
{
	return text;
}

string * ListaParagrafe::end()
{
	return text + Count;
}
void ProcesatorNumarCuvinte::Proceseaza(string str)
{
	string delims = "?!., ";
	int poz = 0;

	while (str.find_first_not_of(delims, 0) != -1) {
		poz = str.find_first_of(delims, 0);
		string cuvant = str.substr(0, poz);
		numarCuvinte[cuvant]++;
		str = str.substr(poz + 1);
	}
	numarCuvinte.erase("");
}
void ProcesatorNumarCuvinte::Print()
{
	map<string, int>::iterator it = numarCuvinte.begin();
	for (; it != numarCuvinte.end(); it++)
		cout << it->first << " " << it->second << endl;
}
void ProcesatorNumarPropozitii::Proceseaza(string str)
{
	for (int i = 0; i < str.size(); i++)
		if (str[i] == '.' || str[i] == '!' || str[i] == '?')
			nrPropozitii++;
}
void ProcesatorNumarPropozitii::Print()
{
	cout << nrPropozitii;
}
int main()
{
	ListaParagrafe L;
	L.Add("Ce usor e Testul la C++!");
	L.Add("Ce faci ? Bine, tu Ce faci ? Tot Bine.");
	Procesator*p = new ProcesatorNumarCuvinte();
	Procesator*p2 = new ProcesatorNumarPropozitii();
	for (auto parag : L)
	{
		p->Proceseaza(parag);
		p2->Proceseaza(parag);
	}
	p->Print();
	p2->Print();
	delete p;
	delete p2;
	cout << endl;
	for (auto par : L)
		cout << par << endl;
	return 0;
}


