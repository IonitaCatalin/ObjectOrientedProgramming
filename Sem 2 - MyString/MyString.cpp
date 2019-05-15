
#include "MyString.h"
#include <string.h>
#include <iostream>
using namespace std;
MyString::MyString()
{
	string = new char[16];
}
MyString::MyString(const char * text)
{	
	int sizeOfText = strlen(text);
	int sizeOfString = 16;
	if (sizeOfText > sizeOfString)
	{
		char*newString = new char[sizeOfText+1];
		strcpy(newString, text);
		delete string;
		string = newString;
		*(string + sizeOfText ) = '\0';
	}
	else
	{
		string = new char[16];
		strcpy(string, text);
	}
}
void MyString::Add(const char *text)
{
	int sizeOfText = strlen(text);
	int sizeOfString = strlen(text);
	if (sizeOfText+sizeOfString > sizeOfString)
	{
		char*newString = new char[sizeOfString + sizeOfString + 1];
		strcpy(newString, string);
		strcat(newString, text);
		delete string;
		string = newString;
		*(string + sizeOfText + sizeOfString) = '\0';
	}
	else strcat(string, text);
}
void MyString::Set(MyString &m)
{
	this->Set(m.string);
}
void MyString::Set(const char *text)
{
	int sizeOfText = strlen(text);
	int sizeOfString = strlen(string);
	if (sizeOfText > sizeOfString)
	{
		char*newString = new char[sizeOfText + 1];
		strcpy(newString, text);
		delete string;
		string = newString;
		*(newString + sizeOfText) = '\0';
	}
	else strcpy(string, text);
}
MyString::~MyString()
{
	
}
void MyString::Add(MyString &m)
{
	this->Add(m.string);
}
const char * MyString::GetText()
{
	return string;
}

MyString * MyString::SubString(unsigned int start, unsigned int size)
{
	int sizeOfString = strlen(string);
	if (start + size > sizeOfString)
	{
		return nullptr;
	}
	else
	{
		char*subString=new char[size];
		for (int i = start; i < start + size; i++)
			*(subString + i) = *(string + i);
		*(subString + size) = '\0';
		return new MyString(subString);
	}
}

bool MyString::Delete(unsigned int start, unsigned int size)
{
	int sizeOfString = strlen(string);
	if (start + size > sizeOfString)
	{
		return false;
	}
	else strcpy(string + start, string + start + size+1);
	return true;
}

int MyString::Compare(const char * text)
{
	return strcmp(string, text);
}
int MyString::Compare(MyString & m)
{
	return this->Compare(m.string);
}

char MyString::GetChar(unsigned int index)
{
	if (index > strlen(string))
		return false;
	return *(string + index);
}

bool MyString::Insert(unsigned int index, const char * text)
{
	return 0;
	/*
	int sizeOfText = strlen(text);
	int sizeOfString = strlen(string);
	if (index > sizeOfString)
		return false;
	//Singura functie care mai trebuie implementata
	/*
	if (sizeOfString + sizeOfText > sizeOfString)
	{
		char*newString = new char[sizeOfString + sizeOfText + 1];
		strncpy(newString, string, index - 1);
		strcat(newString, text);
		strcat(newString, string + index);
	}
	*/
}

int MyString::Find(const char * text)
{
	return strstr(string,text) - string;
}
int MyString::FindLast(const char * text)
{
	char*lastOc = strstr(string, text);
	while (lastOc != nullptr)
		lastOc = strstr(string, text);
	return lastOc - string;

}
bool MyString::operator<(MyString & var)
{
	if (strcmp(this->string,var.string)<0)
		return true;
	else return false;
}
void MyString::swapCont(MyString & n1, MyString & n2)
{
	MyString var = n1;
	n1 = n2;
	n2 = var;
}
char * MyString::begin()
{
	return string;
}
char * MyString::end()
{
	return string + strlen(string);
}
void MyString::printString()
{
	for (unsigned int i = 0; i < strlen(string); i++)
		std::cout << *(string + i);
}
