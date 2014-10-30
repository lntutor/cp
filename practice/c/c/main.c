//
//  main.c
//  c
//
//  Created by Lee Nguyen on 10/26/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include <stdio.h>
#include "simplesort.h"
#include "base.h"

int main(int argc, const char * argv[]) {
    int array [] = {2,3,1,-9,-9,7};
    int size = sizeof(array)/sizeof(array[0]);
    //selection_sort(array, size);
    //bubble_sort2(array, size);
    //insertion_sort(array, size);
    merge_sort(array, 0, size-1);
    print_array(array, size);
    return 0;
}
