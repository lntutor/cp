#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int *array, int size) {
    int numOfShift = 0;
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >=0 && array[j] > key) {
            array[j+1] = array[j];
            numOfShift++;
            j--;
        }
        array[j+1] = key;
    }
    cout << numOfShift << endl;
}

int main() {
    int N;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    insertionSort(array, N);
    return 0;
}
