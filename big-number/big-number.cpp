#include "BigNumber.h"
#include <string.h>
#include <iostream>
using namespace std;

BigNumber::BigNumber()
{
	CharactersCount = 1;
	Number[0] = 0;
}
BigNumber::BigNumber(int value)
{
	if (value == 0)
	{
		CharactersCount = 1;
		Number[0] = 0;
	}
	else
	{
		CharactersCount = 0;
		while (value)
		{
			Number[CharactersCount++] = value % 10;
			value /= 10;
		}
	}
}

BigNumber::BigNumber(const char * number)
{
	CharactersCount = 0;
	int sizeOfString = strlen(number);
	while (sizeOfString)
	{
		Number[CharactersCount++] = (int)*(number + sizeOfString) ;
		sizeOfString--;
	}
}

BigNumber::BigNumber(const BigNumber & number)
{
	
}

void BigNumber::printBigNumber()
{
	for (int i = CharactersCount - 1; i >= 0; i--)
		cout << (*(Number + i)+'0');
}

bool BigNumber::Set(int value)
{
	if (value == 0)
	{
		CharactersCount = 1;
		Number[0] = 0;
		return true;
	}
	else
	{
		CharactersCount = 0;
		while (value)
		{
			Number[CharactersCount++] = value % 10;
			value /= 10;
		}
		return true;
	}
	return false;
}

bool BigNumber::Set(const char * number)
{
	strcpy(this->Number, number);
	this->CharactersCount = strlen(number);
	return true;
}
