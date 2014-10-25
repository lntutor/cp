//
//  main.c
//  c
//
//  Created by Lee Nguyen on 10/26/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include <stdio.h>
#include "selectionsort.h"
#include "base.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int array [] = {2,3,1,-9,7};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array, size);
    print_array(array, size);
    return 0;
}
