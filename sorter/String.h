//
//  String.h
//  sorter
//
//  Created by Grant Furgiuele on 5/28/14.
//  Copyright (c) 2014 GrantFurgiuele. All rights reserved.
//

#ifndef __sorter__String__
#define __sorter__String__

#include <iostream>
#include <algorithm> // std::copy
#include <cstddef> // std::size_t

class String
{
private:
	char* value;
	std::size_t arrSize;
    
public:
	String(std::size_t size = 0) : arrSize(size)
	{
		value = arrSize ? new char[arrSize]() : 0;
	}
	
	String(const char* str) : arrSize(strlen(str))
	{
		value = arrSize ? new char[arrSize]() : 0;
		std::copy<const char*, char*>(str, str + arrSize, value);
	}
    
	// copy-constructor
	String(const String& other) : arrSize(other.arrSize)
	{
		// note that this is non-throwing, because of the data
		// types being used; more attention to detail with regards
		// to exceptions must be given in a more general case, however
		value = arrSize ? new char[arrSize]() : 0;
		std::copy<char*, char*>(other.value, other.value + arrSize, value);
	}
    
	int length();
	char operator[](int);
	String& operator=(const char*);
	String& operator=(String);
	bool operator>(String& other);
	bool operator<(String& other);
    friend std::ostream& operator<<(std::ostream& os, String& obj);
    
	~String();
    
	friend void swap(String& first, String& second)
	{
		using std::swap;
		swap(first.arrSize, second.arrSize);
		swap(first.value, second.value);
	}
};

#endif /* defined(__sorter__String__) */
