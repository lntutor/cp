//
//  EnormousInputTest.c
//  c
//
//  Created by Lee Nguyen on 11/1/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include <stdio.h>

int main1 (){
    unsigned int n, value, result;
    scanf("%d", &n);
    scanf("%d", &value);
    result = 0;
    while (n>0) {
        int temp;
        scanf("%d", &temp);
        if (temp%value==0) {
            result++;
        }
        n--;
    }
    printf("%d\n", result);

    return 0;
}