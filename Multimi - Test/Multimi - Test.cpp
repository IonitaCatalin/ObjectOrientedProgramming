#include "pch.h"
#include <iostream>
#include <algorithm>
#include "Multime.h"
using namespace std;
int compareCresc(int a, int b)
{
	if (a > b)
		return 1;
	else return -1;
	return 0;
}
int compareDesc(int a, int b)
{
	if (a < b)
		return 1;
	else return -1;
	return 0;
}
int main()
{
	Multime p, q;
	p.add(3); 
	p.add(7);
	p.add(6);
	p.add(12);
	p.add(121);
	q.add(6);
	q.add(12);
	q.add(7);
	q.add(121);
	
	cout << "Multimea 1:";
	p.print();
	cout << endl;
	cout << "Multimea 2:";
	q.print();
	cout << endl;
	cout << "Multimea 1 - Size:" << p.GetSize() << endl;
	cout << "Multimea 2 - Size:" << q.GetSize() << endl;
	cout << "Maxim din mult 1:" << p.Max() << endl;
	cout << "Minim din mult 1:" << p.Min() << endl;
	Multime inters, reun;
	inters = p | q;
	reun = p & q;
	cout << "Intersectia:";
	inters.print();
	cout << endl;
	cout << "Reuniune:";
	reun.print();
	cout << endl;
	cout << "Sortat Cresc.Mult I:";
	p.Sort(compareCresc);
	p.print();
	cout << endl;
	p.Sort(compareDesc);
	cout << "Sortat Desc.MultI:";
	p.print();
	return 0;
}