// C++ program for implementation of Heap Sort
#include <iostream>
#include <queue>
using namespace std;

///* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
//
//// To heapify a subtree rooted with node i which is
//// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    //Build max heap for all subtree
    for (int i = n/2 - 1; i >=0; i--)
        heapify(arr, n, i);

    printf("Max heap is\n");
    printArray(arr, n);
    for (int i = n-1; i >=0; i--) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i -1;
        while(j >=0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int partition(int * array, int lo, int hi) {
    int i = lo;
    int pivot = array[hi];//swapping index
    for (int j = lo; j < hi; j++) {
        if (array[j] < pivot) {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[hi]);
    return i;
}

void quicksort(int * array, int lo, int hi) {
    if(lo < hi) {
        int p = partition(array, lo, hi);
        quicksort(array, lo, p-1);
        quicksort(array, p+1, hi);
    }
}


// Driver program
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 1 , 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    //    heapSort(arr, n);
    //    insertionSort(arr, n);
    quicksort(arr, 0, n-1);
    cout << "Sorted array is \n";
    printArray(arr, n);
    return 1;

}
