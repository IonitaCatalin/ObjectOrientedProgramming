#pragma once
#include <utility>
#include <initializer_list>
#include <iostream>
#include <string>
using namespace std;
template<typename T>
class MyMap
{
private:
	pair<string, T>*el;
	int Count;
public:
	MyMap();
	~MyMap();
	MyMap(initializer_list<pair<string, T>> list);
	pair<string, T>*begin();
	pair<string, T>*end();
	bool operator()(string key);
	T operator[](string key);
	bool Add(string key, T mappedKey);
	void print();
	bool Del(string key);
	bool operator <(MyMap&n1);
	bool operator =(MyMap&n1);
	MyMap operator &(MyMap<T>&n1);
	MyMap operator | (MyMap<T>&n1);
};

template<typename T>
inline MyMap<T>::MyMap()
{
	Count = 0;
}

template<typename T>
inline MyMap<T>::~MyMap()
{

}
template<typename T>
inline MyMap<T>::MyMap(initializer_list<pair<string, T>> list)
{
	el = new pair<string, T>[list.size()];
	Count = list.size();
	int pos = 0;
	for (auto it = list.begin(); it != list.end(); it++)
	{
		el[pos].first = it->first;
		el[pos].second = it->second;
		pos++;
	}
}

template<typename T>
inline pair<string, T>* MyMap<T>::begin()
{
	return &el[0];
}
template <typename T>
inline pair<string, T>* MyMap<T>::end()
{
	return &el[Count];
}

template<typename T>
inline bool MyMap<T>::operator()(string key)
{
	for (int i = 0; i < Count; i++)
		if (el[i].first == key)
			return true;
	return false;
}

template<typename T>
inline T MyMap<T>::operator[](string key)
{
	for (int i = 0; i < Count; i++)
		if (el[i].first == key)
			return el[i].second;
}
template<typename T>
inline bool MyMap<T>::Add(string key, T mappedKey)
{
	if (el == nullptr)
	{
		el = new pair<string, T>;
		Count = 1;
		el->first = key;
		el->second = mappedKey;
		return true;
	}
	else
	{
		bool exists = false;
		int pos;
		for (int i = 0; i < Count; i++)
			if (el[i].first == key)
			{
				exists = true;
				pos = i;
			}
		if (!exists)
		{
			pair<string, T>*newEl = new pair<string, T>[Count + 1];
			for (int i = 0; i < Count; i++)
				newEl[i] = el[i];
			newEl[Count].first = key;
			newEl[Count ].second = mappedKey;
			el = newEl;
			Count++;
			return true;
		}
		else
		{
			if (el[pos].second < mappedKey)
				el[pos].second = mappedKey;
		}
	}
	return false;
}
template<typename T>
inline void MyMap<T>::print()
{
	for (int i = 0; i < Count; i++)
		cout << el[i].first << " " << el[i].second << endl;
}

template<typename T>
inline bool MyMap<T>::Del(string key)
{
	for (int i = 0; i < Count; i++)
	{
		
		if (el[i].first == key)
		{
			if (i == Count - 1)
			{
				Count--;
				return true;
			}
			for (int j=i;j<=Count-2;j++)
				el[j] = el[j + 1];
			Count--;
			return true;
		}
	}
	return false;
}

template<typename T>
inline bool MyMap<T>::operator<(MyMap & n1)
{
	return false;
}

template<typename T>
inline bool MyMap<T>::operator=(MyMap & n1)
{
	if (n1.Count > this->Count)
	{
		pair<string, T>*newEl = new pair<string, T>[n1.Count];
		for (int i = 0; i < n1.Count; i++)
		{
			newEl[i].first = n1[i].first;
			newEl[i].second = n1[i].second;
		}
		this.Count = n1.Count;
	}
	else
	{
		for (int i = 0; i < this.Count; i++)
		{
			el[i].first = n1[i].first;
			el[i].second = n1[i].second;
		}
		this.Count = n1.Count;
	}
}

template<typename T>
inline MyMap<T> MyMap<T>::operator&(MyMap<T>& n1)
{
	MyMap<T>concat = n1;
	for (int i = 0; i < this->Count; i++)
		concat.Add(this->el[i].first, this->el[i].second);
	return concat;
}

template<typename T>
inline MyMap<T> MyMap<T>::operator|(MyMap<T>& n1)
{
	MyMap<T>inst;
	for (int i = 0; i < this->Count; i++)
		for (int j = 0; j < n1.Count; j++)
			if (this->el[i].first == this->el[i].first)
				inst.Add(this->el[i].first, this->el[i].second);
			return inst;
}

