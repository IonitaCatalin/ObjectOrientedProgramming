#include <string>
#include <iostream>
#include "pch.h"
#include "MyMap.h"
using namespace std;
template<typename H, typename T>
bool MyMap<H,T>::Add(const H key, const T*var)
{
	if (head == NULL)
	{
		head = new inMap;
		head->value->first = key;
		head->value->second = var;
		head->next = NULL;
		last = head;
		return true;
	}
	else
	{
		inMap*newNode = new inMap;
		newNode->value->first = key;
		newNode->value->second = var;
		newNode->next = head;
		head = newNode;
		return true;
	}
	return false;
}
