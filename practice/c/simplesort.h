//
//  selectionsort.h
//  c
//
//  Created by Lee Nguyen on 10/26/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#ifndef __c__selectionsort__
#define __c__selectionsort__

#include <stdio.h>

/*
 The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
 1) The subarray which is already sorted.
 2) Remaining subarray which is unsorted.
 */
void selection_sort (int array[], int n);// n = size of array

/*
 Bubble Sort is the simplest sorting algorithm that works 
 by repeatedly swapping the adjacent elements if they are in wrong order.
 */
void bubble_sort (int array[], int n);// n = size of array

void bubble_sort2 (int array[], int n);// n = size of array

/*
 insertion_sort(arr, n)
 Loop from i = 1 to n-1.
 ……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]
 */

void insertion_sort (int array[], int n); // n = size of array

#endif /* defined(__c__selectionsort__) */
