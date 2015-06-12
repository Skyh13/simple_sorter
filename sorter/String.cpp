//
//  String.cpp
//  sorter
//
//  Created by Grant Furgiuele on 5/28/14.
//  Copyright (c) 2014 GrantFurgiuele. All rights reserved.
//


#include "String.h"
#include <iostream>

using namespace gfurg;

String::String() : arrSize(0)
{ 
	value = arrSize ? new char[arrSize]() : 0;
}

String::String(std::size_t size = 0) : arrSize(size)
{
	value = arrSize ? new char[arrSize]() : 0;
}

String::String(const char* str) : arrSize(strlen(str))
{
	value = arrSize ? new char[arrSize]() : 0;
	std::copy<const char*, char*>(str, str + arrSize, value);
}

// copy-constructor
String::String(const String& other) : arrSize(other.arrSize)
{
	// note that this is non-throwing, because of the data
	// types being used; more attention to detail with regards
	// to exceptions must be given in a more general case, however
	value = arrSize ? new char[arrSize]() : 0;
	std::copy<char*, char*>(other.value, other.value + arrSize, value);
}

int String::length()
{
	return(strlen(value));
}

char String::operator[] (int element)
{
	char ret_val = 0;
	if (element >= 0 && element < this->length())
	{
		ret_val = this->value[element];
	}
	return ret_val;
}

String& String::operator=(const char* str)
{
	arrSize = strlen(str);
	value = arrSize ? new char[arrSize]() : 0;
	std::copy<const char*, char*>(str, str + arrSize, value);

	return *this;
}

String& String::operator=(String str)
{
	swap(*this, str);

	return *this;
}

bool String::operator>(String& other)
{
	int x = 0;
	while (1)
	{
		if (x >= other.length())
		{
			return false;
		}
		else if (x >= this->length())
		{
			return true;
		}
		if (this->value[x] > other[x])
		{
			return true;
		}
		if (this->value[x] < other[x])
		{
			return false;
		}
		x++;
	}
}

bool String::operator<(String& other)
{
	int x = 0;
	while (1)
	{
		if (x >= other.length())
		{
			return true;
		}
		else if (x >= this->length())
		{
			return false;
		}
		if (this->value[x] > other[x])
		{
			return false;
		}
		if (this->value[x] < other[x])
		{
			return true;
		}
		x++;
	}
}

String::~String()
{
	delete value;
}
