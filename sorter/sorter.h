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

class Sorter
{
public:
    template <typename T>
    int mergeSort(T*, int);
    template <typename T>
    int bubbleSort(T*, int);
    template <typename T>
    int binarySort(T*, int);
};

#endif /* defined(__sorter__sorter__) */
