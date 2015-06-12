//
//  sorter.h
//  sorter
//
//  Created by Grant Furgiuele on 5/18/14.
//  Copyright (c) 2014 GrantFurgiuele. All rights reserved.
//

#ifndef __sorter__sorter__
#define __sorter__sorter__

#include <iostream>
#include "String.h"

using namespace gfurg;

template <class T> T* merge(T* input, int length);

class Sorter
{
public:
	template <class T> int mergeSort(T*, int);
	template <class T> int bubbleSort(T*, int);
	template <class T> int binarySort(T*, int);
};

template<class T> int Sorter::mergeSort(T* input, int length)
{
	T* temp = merge<T>(input, length);
	if (temp != NULL)
	{
		std::copy(&temp[0], &temp[length - 1], input);
	}
	return 0;
};

template<class T> int Sorter::bubbleSort(T* input, int length)
{
	int sortedMarker = 1;
	int curMarker = 1;

	if (length <= 0)
	{
		return -1;
	}
	else
	{
		while (sortedMarker < length)
		{
			for (curMarker = sortedMarker; curMarker > 0; curMarker--)
			{
				if (input[curMarker] < input[curMarker - 1])
				{
					T temp = input[curMarker - 1];
					input[curMarker - 1] = input[curMarker];
					input[curMarker] = temp;
				}
			}
			sortedMarker++;
		}
	}

	return 0;
};

template <typename T>
T* merge(T* input, int length)
{
	if (length == 1)
	{
		return input;
	}
	if (length > 1)
	{
		int left_length = length / 2;
		int right_length = length - (length / 2);
		T* left = &input[0];
		T* right = &input[(length / 2)];

		left = merge(left, left_length);

		right = merge(right, right_length);

		T* merged_arr;
		merged_arr = new T[length];

		int left_pointer = 0;
		int right_pointer = 0;

		for (int x = 0; x < length; x++)
		{
			if (left_pointer < left_length &&
				right_pointer < right_length)
			{
				if (left[left_pointer] < right[right_pointer])
				{
					merged_arr[x] = left[left_pointer];
					left_pointer++;
				}
				else
				{
					merged_arr[x] = right[right_pointer];
					right_pointer++;
				}
			}
			else if (left_pointer >= left_length &&
				right_pointer < right_length)
			{
				merged_arr[x] = right[right_pointer];
				right_pointer++;
			}
			else if (left_pointer < left_length &&
				right_pointer >= right_length)
			{
				merged_arr[x] = left[left_pointer];
				left_pointer++;
			}
		}

		std::copy(merged_arr, merged_arr + length, input);
		delete[] merged_arr;
		return input;

	}
	else
	{
		return NULL;
	}
};

#endif /* defined(__sorter__sorter__) */
