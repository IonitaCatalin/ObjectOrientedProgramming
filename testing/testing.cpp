#include <iostream>
#include <string.h>
using namespace std;
template <typename T>
void sort(T v[], int n, const char *s) {
	bool b = true;
	T aux;
	while (b) {
		b = false;
		if (strcmp(s, "Crescator") == 0)
			for (int i = 1; i < n - 1; i++) {
				if (v[i - 1] > v[i + 1]) {
					aux = v[i + 1];
					v[i + 1] = v[i - 1];
					v[i - 1] = aux;
					b = true;
				}
			}
		else if (strcmp(s, "Descrescator") == 0)
			for (int i = 0; i < n - 1; i++) {
				if (v[i] < v[i + 1]) {
					aux = v[i + 1];
					v[i + 1] = v[i];
					v[i] = aux + 1;
					b = true;
				}
			}
		else {
			cout << "Ordinul de comparatie gresit introdus"; return;
		}
	}
}
bool Test1()
{
	/*
		Input:1,2,3,18,21,0 - "Descrescator"
		Expected:0,1,2,3,18,21
	*/
	int sizeofTest = 6;
	int v[] = { 1,2,3,18,21,0 };
	int rec[] = { 1,2,3,18,21,0 };
	sort<int>(rec,sizeofTest,"Crescator");
	for (int i = 0; i < sizeofTest; i++)
		if (v[i] != rec[i])
			return false;
	return true;
}
bool Test2()
{
	/*
		Input:2,3 "Crescator"
		Expected: 2,3
	*/
	int sizeofTest = 2;
	int v[] = { 2,3 };
	int rec[] = { 2,3 };
	sort<int>(rec, sizeofTest, "Crescator");
	for (int i = 0; i < sizeofTest; i++)
		if (v[i] != rec[i])
			return false;
	return true;
}
bool Test3()
{
	/*
	Input:2,3 - "Descrescator"
	Expected:3,2
	*/
	int sizeofTest = 2;
	int v[] = { 2,3 };
	int rec[] = { 3,2 };
	sort<int>(rec, sizeofTest, "Descrescator");
	for (int i = 0; i < sizeofTest; i++)
		if (v[i] != rec[i])
			return false;
	return true;
}
int main()
{
	cout << "Testul 1:" << Test1() << endl;
	cout << "Testul 2:" << Test2() << endl;
	cout << "Testul 3:" << Test3() << endl;
	return 0;
}