//
//  smallfactorial.c
//  c
//
//  Created by Lee Nguyen on 11/2/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//
#include <stdio.h>

int factorial1(unsigned int value){
    if (value==1) {
        return 1;
    }else
        return value*factorial1(value-1);
}

int main1 (){
    int n;
    scanf("%d", &n);
    int array[n];
    int i;
    
    for (i = 0; i<n; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i<n; i++) {
        printf("%d\n", factorial1(array[i]));
    }
    
    return 0;
}
