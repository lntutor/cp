//
//  love_letter_mystery.c
//  c
//
//  Created by Lee Nguyen on 11/5/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void findMysteryLoveLetter(char *data){
    int size = 0;
    int result = 0;
    while (*(data + size) != '\0') {
        size++;
    }
    size--;
    int i = size/2;
    int j = 0;
    for (j = 0; j<=i; j++) {
        result += abs(*(data + j) - *(data + (size -j)));
    }
    printf("%d\n", result);
}

int mainloveletter() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    int i;
    for (i=0; i<n; i++) {
        char input [10001];
        memset(input, 0, sizeof(input));
        scanf("%s", input);
        
        findMystery(input);
    }
    return 0;
}
