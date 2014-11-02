//
//  factorial.c
//  c
//
//  Created by Lee Nguyen on 11/1/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include <stdio.h>

int factorialfac(unsigned int value){
    int result = 0;
    int i = 5;
    for (i = 5; value/i>0; i*=5) {
        result += value/i;
    }
    return result;
}

int mainfac (){
    int n;
    scanf("%d", &n);
    int array[n];
    int i;
    
    for (i = 0; i<n; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i<n; i++) {
        printf("%d\n", factorialfac(array[i]));
    }
    
    return 0;
}
