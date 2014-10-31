//
//  atm.c
//  c
//
//  Created by Lee Nguyen on 10/31/14.
//  Copyright (c) 2014 LeeAnn. All rights reserved.
//

#include <stdio.h>

int atm () {
    
    float balance;
    int withdraw;
    while (1) {
        scanf("%d", &withdraw);
        scanf("%f", &balance);
        float result = balance - withdraw - 0.5f;
        result =  (result>=0 && withdraw%5==0)?result:balance;
        printf("%f", result);
        break;
    }
    return 0;
}

