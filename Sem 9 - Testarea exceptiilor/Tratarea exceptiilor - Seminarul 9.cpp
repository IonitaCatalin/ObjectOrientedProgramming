#include <iostream>
#include "Array.h"
#include<string>
int compDescr(const int&x, const int&y)
{
	if (x == y)
		return 0;
	if (x < y)
		return 1;
	else return -1;
}
int compCresc(const int&x, const int&y)
{
	if (x == y)
		return 0;
	if (x > y)
		return 1;
	else return -1;
}
using namespace std;
int main()
{
	Array<int> arr(11);
	Array<int> var(4);
	CompCrescator cmp;
	arr += 3; arr += 4; arr += 7; arr += 19; arr += 28;
	var += 123; var += 226;
	cout << "Elementele listei sunt:";
	for (auto iterator : arr)
		cout << iterator << " "; cout << endl;
	cout << "Marimea listei este:" << arr.GetSize() << endl;
	cout << "Elementul de pe pozitia 1217 este:";
	arr[1217];
	cout << endl;
	cout << "Inseram elementul 78 la sfarsitul listei:";
	arr += 78;
	arr.printArray();
	cout << "Inseram elementul 27 pe pozitia 0:";
	arr.Insert(0,27);
	arr.printArray();
	cout << "Adaugam lista (123,226) pe pozitia 3:";
	arr.Insert(3, var);
	arr.printArray();
	cout << "Stergem elementul de pozitia 3:";
	arr.Delete(3);
	arr.printArray();
	cout << "Gasim pozitia elementului 19:" << arr.Find(19) << endl;
	cout << "Gasim pozitia elementului 19:" << arr.Find(19,&cmp) << endl;
	cout << "Lista sortata crescator:";
	arr.Sort();
	arr.printArray();
	cout << "Lista sortata descrescator:";
	arr.Sort(compDescr);
	arr.printArray();
	cout << "Sortam lista folosind obiect de comparatie:";
	arr.Sort(&cmp);
	arr.printArray();
	arr.Sort();
	cout << "Verificam daca exista elementul 123:" << arr.BinarySearch(123) << endl;
	cout << "Verificam daca exista elementul 19:" << arr.BinarySearch(19,&cmp) << endl;
	return 0;
}

