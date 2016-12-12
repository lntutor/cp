// Given an int array A,
// return an int array B that A[i + B[i]] is the first element in A after A[i] that is greater than or equal to A[i]


#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int A [] = {2,1,3,4,5,6};

  // A[0 + B[0]] = 3;
  // B[i] + i = maxIndex; ==> B[i] = maxIndex - i

  int N = sizeof(A)/sizeof(A[0]);
  int B [N];
  memset(B, 0, N*sizeof(B[0]));
  int maxIndex = -1;
  for(int i = 0; i < N; i++) {
    cout << "i " << i << endl;
    for(int j = i + 1; j < N; j++) {
      if (A[j] > A[i]) {
        maxIndex = j;
        break;
      }
    }
    cout << "max index " << maxIndex << endl;
    if (maxIndex != -1) B[i] = maxIndex - i;
    maxIndex = -1;//reset
  }
  cout << "Hello World" << endl;

  for(int i = 0; i < N; i++) cout << B[i] << " ";
  return 1;
}
