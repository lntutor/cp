//
//  heapsort.c
//  c
//
//  Created by Lee Nguyen on 11/11/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simplesort.h"


void maxHeap(struct MaxHeap* heap, int index){
    int maxIndex = index;
    int right = (index<<1) + 1;
    int left = (index<<1);
    if (right < heap->size && heap->array[maxIndex] < heap->array[right]) {
        maxIndex = right;
    }
    
    if (left < heap->size && heap->array[maxIndex] < heap->array[left]) {
        maxIndex = left;
    }
    
    if (maxIndex!=index) {
        swap(&heap->array[index], &heap->array[maxIndex]);
        maxHeap(heap, maxIndex);
    }
}

struct MaxHeap* buildHeap(int* array, int size){
    struct MaxHeap* heap = (struct MaxHeap *) malloc(sizeof(struct MaxHeap));
    heap->array = array;
    heap->size = size;
    int i;
    for ( i=(size-2)/2; i>=0; i--) {
        maxHeap(heap, i);
    }
    return heap;
}



void heapSort(int* array, int size){
    struct MaxHeap*heap = buildHeap(array, size);
    while (heap->size) {
        swap(&heap->array[0], &heap->array[heap->size-1]);
        heap->size--;
        maxHeap(heap, 0);
    }
}
