//
//  heapsort.h
//  c
//
//  Created by Lee Nguyen on 11/11/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#ifndef __c__heapsort__
#define __c__heapsort__

#include <stdio.h>
struct MaxHeap {
    int *array;
    int size;
};

struct MaxHeap* buildHeap(int* array, int size);

void maxHeap(struct MaxHeap* heap, int index);

void heapSort(int* array, int size);

#endif /* defined(__c__heapsort__) */
