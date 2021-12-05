#include "pch.h"
#include "convertSort.h"
#include <iostream>
#include <string>
#include <set>
#include <fstream>
using namespace std;
ifstream fin("data.in");
int toInt(string var)
{
	int toInt = 0;
	string::iterator it;
	for (it = var.begin(); it != var.end(); it++)
		if (*it >= 48 && *it <= 57)
			toInt = toInt*10+(*it - '0');
	return toInt;

}
void convertAndSort()
{
	string var;
	set<int> sortedStr;
	while (getline(fin, var, ','))
		sortedStr.insert(toInt(var));
	set<int>::iterator it;
	for (it = sortedStr.begin(); it != sortedStr.end(); it++)
		cout << *it << " ";
}
int main()
{
	convertAndSort();
}

