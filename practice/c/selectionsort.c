//
//  selectionsort.c
//  c
//
//  Created by Lee Nguyen on 10/26/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include "selectionsort.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int array[], int n){
    int i, j;
    for (i=0; i<n-1; i++) {
        int min = i;
        for (j=i+1; j<n; j++) {
            if (array[j]< array[min]) {
                min = j;
            }
        }
        swap(&array[min], &array[i]);
    }
}