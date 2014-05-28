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

int main(int argc, const char * argv[])
{

    int testArr[] = {5, 3, 7, 2, 0, 4, 6};
    String testArr2[] = { String("cat"), String("dog"), String("boy"), String("girl") };
    
    Sorter sortObj;
    
    sortObj.bubbleSort<int>(testArr, 7);
    
    sortObj.mergeSort<String>(testArr2, 4);
    
    for(int x = 0; x < 4; x++)
    {
        std::cout << testArr2[x] << "\n";
    }
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

