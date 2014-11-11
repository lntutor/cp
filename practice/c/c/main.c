#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "heapsort.h"

void findMystery(char *data){
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

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //int n;
    //scanf("%d", &n);
    int array[8] = {2,3,1,88,3,111,-5,6};
    heapSort(array, 8);
    int i;
    for (i=0; i<8; i++) {
        printf("%d\n", array[i]);
    }
    return 0;
}
