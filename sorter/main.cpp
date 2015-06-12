//
//  main.cpp
//  sorter
//
//  Created by Grant Furgiuele on 5/18/14.
//  Copyright (c) 2014 GrantFurgiuele. All rights reserved.
//

#include <iostream>
#include "sorter.h"
#include "String.h"

using namespace std;
using namespace gfurg;

int main(int argc, const char * argv[])
{
	gfurg::String input2[] = { "girl", "dog", "boy", "cat" };

	int input[12] = { 5, 3, 8, 2, 6, 3, 9, 1, 3, 2, 7, 5 };
	int* result;
	gfurg::String* result2;

	Sorter sortObj;

	sortObj.bubbleSort<int>(input, 12);

	sortObj.mergeSort<String>(input2, 4);

	for (int x = 0; x < 12; x++)
	{
		std::cout << input[x] << "\n";
	}

	for (int x = 0; x < 4; x++)
	{
		std::cout << input2[x] << "\n";
	}

	return 0;
}

