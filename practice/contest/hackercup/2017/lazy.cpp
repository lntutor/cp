#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#define MaxN 2005
#define PI 3.14159265
#define REP(i, a, b) for(int i = a; i <= b; i++)

int T;

#define MIN_LIMIT 50


int solve(int * array, int currentArraySize, int currentMaxIndex) {

  if (currentArraySize < 0 || currentMaxIndex < 0) return 0;

  int maxValue = array[currentMaxIndex];

  int minPackages = 0;

  if (MIN_LIMIT%maxValue == 0) {
     minPackages = MIN_LIMIT/maxValue;
  } else {
     minPackages = MIN_LIMIT/maxValue + 1;
  }

  if (minPackages > currentArraySize) return 0;

  return 1 + solve(array, currentArraySize - minPackages, currentMaxIndex - 1);

}

int main() {
	ofstream myfile;
	myfile.open("output.txt");
	FILE * pFile = fopen("input.txt", "r+");

	fscanf(pFile, "%d", &T);

	REP(i, 1, T)
	{
    int N;
		fscanf(pFile, "%d", &N);
    int array[N];
    REP(j, 0, N-1) {
  		fscanf(pFile, "%d", &array[j]);
    }
    sort(array, array + N);

		myfile << "Case #" << i << ":" << " " << solve(array, N, N-1) << endl;
	}
	myfile.close();
}
