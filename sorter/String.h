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

namespace gfurg
{

	class String
	{
	private:
		char* value;
		std::size_t arrSize;

	public:
		String();
		String(std::size_t);
		String(const char* str);
		String(const String& other);

		int length();
		char operator[](int);
		String& operator=(const char*);
		String& operator=(String);
		bool String::operator>(String& other);
		bool String::operator<(String& other);

		~String();

		
		friend std::ostream& operator<<(std::ostream& os, const String& str)
		{
			for (int x = 0; x < str.arrSize; x++) {
				os << str.value[x];
			}
			return os;
		}
		
		
		friend void swap(String& first, String& second)
		{
			using std::swap;
			swap(first.arrSize, second.arrSize);
			swap(first.value, second.value);
		}
	};

}

#endif /* defined(__sorter__String__) */
