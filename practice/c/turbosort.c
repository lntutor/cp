//
//  turbosort.c
//  c
//
//  Created by Lee Nguyen on 11/2/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include <stdio.h>


//
//  main.c
//  c
//
//  Created by Lee Nguyen on 10/26/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//


#include <stdio.h>


void swap1(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
 * Implementation of merge sort
 */
void merge1(int array[], int left, int mid, int right){
    
    int i = 0;
    int j =0;
    int k;
    int firstHalf = mid - left + 1;
    int secondHalf = right - mid;
    
    int arrLeft[firstHalf];
    int arrRight[secondHalf];
    /* Copy data to temp arrays arrLeft[] and arrRight[] */
    for (i = 0; i<firstHalf; i++) {
        arrLeft[i] = array[left + i];
    }
    for (i = 0; i< secondHalf; i++) {
        arrRight[i] = array[mid + 1 + i];
    }
    
    /* Merge the temp arrays back into arr[l..r]*/
    k = left;
    i = 0;
    j = 0;
    
    while (i<firstHalf && j <secondHalf) {
        if (arrLeft[i] <= arrRight[j]) {
            array[k] = arrLeft[i];
            i++;
        } else {
            array[k] = arrRight[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of arrLeft[], if there are any */
    while (i<firstHalf) {
        array[k] = arrLeft[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of arrRight[], if there are any */
    while (j<secondHalf) {
        array[k] = arrRight[j];
        j++;
        k++;
    }
}

void merge_sort1(int array[], int left, int right) {
    if (right>left) {
        int mid = left + (right-left)/2;
        merge_sort1(array, left, mid);
        merge_sort1(array, mid+1, right);
        merge1(array, left, mid, right);
    }
}
int maintubor (){
    int n;
    scanf("%d", &n);
    int array[n];
    int i;
    
    for (i = 0; i<n; i++) {
        scanf("%d", &array[i]);
    }
    
    merge_sort1(array, 0, n-1);
    for (i = 0; i<n; i++) {
        printf("%.0d\n", array[i]);
    }
    
    return 0;
}
