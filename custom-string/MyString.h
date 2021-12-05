#pragma once
class MyString
{
	char*string;
public:
	MyString();
	MyString(const char * text);
	~MyString();
	void printString();
	void Set(const char *text);
	void Set(MyString &m);
	void Add(const char *text);
	void Add(MyString &m);
	const char* GetText();
	MyString* SubString(unsigned int start, unsigned int size);
	bool Delete(unsigned int start, unsigned int size);
	int Compare(const char * text);
	int Compare(MyString &m);
	char GetChar(unsigned int index);
	bool Insert(unsigned int index, const char* text);
	int Find(const char * text);
	int FindLast(const char * text);
	bool operator <(MyString & var);
	void swapCont(MyString&n1, MyString &n2);
	char*begin();
	char*end();
};
