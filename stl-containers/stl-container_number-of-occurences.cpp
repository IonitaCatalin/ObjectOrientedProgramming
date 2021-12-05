#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
ifstream fin("data.txt");
void numberOfOccurences()
{
	string var;
	size_t pos = 0;
	string token;
	vector<pair<int, string>> occ;
	while (getline(fin, var, '.'))
	{
		do
		{
			token = var.substr(0, pos);
			cout << token << " ";
			var.erase(0, pos);
		} 
		while (pos = var.find(' ') != string::npos);
	}
}
int main()
{
	numberOfOccurences();
}
