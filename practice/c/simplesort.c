//
//  selectionsort.c
//  c
//
//  Created by Lee Nguyen on 10/26/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include "simplesort.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
 * Implementation of selection sort
 */
void selection_sort(int array[], int n){
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

/*
 * Implementation of buble sort
 */

void bubble_sort(int array[], int n) {
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j <=i; j++) {
            if (array[j]>array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}