//
//  String.cpp
//  sorter
//
//  Created by Grant Furgiuele on 5/28/14.
//  Copyright (c) 2014 GrantFurgiuele. All rights reserved.
//


#include "String.h"


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

std::ostream& operator<<(std::ostream& os, String& obj)
{
    int x = 0;
    for(x = 0; x < obj.length(); x++)
    {
        os.put(obj[x]);
    }
    return os;
}

String::~String()
{
	delete value;
}
