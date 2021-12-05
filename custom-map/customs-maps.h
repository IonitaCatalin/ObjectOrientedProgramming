#pragma once
#include <utility>
#include <string>
using namespace std;
template<typename H,typename T>
class MyMap
{
private:
	struct inMap
	{
		pair<H, T*> value;
		inMap*next;
	};
	inMap*head, *last;
public:
	bool Add(const H key, const T*var);
};

