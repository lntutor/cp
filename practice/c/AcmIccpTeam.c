//
//  AcmIccpTeam.c
//  c
//
//  Created by Lee Nguyen on 11/14/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include <stdio.h>

#include <string.h>
#include <math.h>
#include <stdlib.h>

int countNumOfOne(char * item, int length){
    int count = 0;
    while(length--){
        if (item[length]=='1')
            count++;
    }
    return count;
}

int countTopics(char * item1, char * item2, int length){
    int count = 0;
    while(length--){
        if (item1[length]=='1' || item2[length]=='1')
            count++;
    }
    return count;
}
/*
int main() {
    int N, M, i, j;
    scanf("%d", &N);
    scanf("%d", &M);
    char array[N][M];
    char tmp[M];
    for (i=0; i<N; i++){
        scanf("%s", array[i]);
    }
    int maxTopic = 0;
    int numOfTeam = 1;
    for (i=0; i< N-1; i++){
        for (j=i+1; j<N; j++ ){
            int countTopic = countTopics(array[i], array[j], M);
            if (countTopic > maxTopic){
                maxTopic = countTopic;
                numOfTeam = 1;
            } else if (countTopic == maxTopic && countTopic!=0){
                numOfTeam++;
            }
        }
    }
    printf("%d\n", maxTopic);
    printf("%d\n", numOfTeam);
    return 0;
}
*/
