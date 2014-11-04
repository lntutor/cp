//
//  gameofthrone.c
//  c
//
//  Created by Lee Nguyen on 11/3/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void findPalind(char *arr)
{
    
    int flag = 1;
    // Find the required answer here. Print Yes or No at the end of this function depending on your inspection of the string
    int array[256];
    int i = 0;
    for (i=0; i < 256; i++) {
        array[i] = 0;
    }
    i = 0;
    while(i<100001 && *(arr + i)!= '\0'){
        array[*(arr + i)] +=1;
        //printf("%c ", *(arr + i));
        i++;
    }
    
    int numOfOdd = 0;
    for (i=0; i < 256; i++) {
        if (array[i]!=0) {
            if (array[i]%2==0) {
                continue;
            } else {
                numOfOdd++;//1 Odd-character type is acceptable, if >=2 ==> can not be palindrone
                if (numOfOdd==2) {
                    flag = 0;
                    break;
                }
            }
        }
    }
    if (flag==1)
        printf("YES\n");
    else
        printf("NO\n");
    
    return;
}
int maindsaf() {
    
    char arr[100001];
    memset(arr, 0, 100001);
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}

