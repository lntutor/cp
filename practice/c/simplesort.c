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
 * Implementation of bubble sort
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

void bubble_sort2(int array[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n-1; j >=i; j--) {
            if (array[j]<array[j-1]) {
                swap(&array[j], &array[j-1]);
            }
        }
    }
}

/*
 Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.

 */

void insertion_sort(int array[], int n){
    for (int i = 1; i <n; i++) {
        int key = array[i];
        int insert_index = -1;
        
        for (int j = i-1; j>=0; j--) {
            if (array[j]>key) {
                array[j+1] = array[j];
                insert_index = j;
            }else {
                break;// found insert index
            }
        }
        if (insert_index>=0) {
            array[insert_index] = key;
        }
    }
}