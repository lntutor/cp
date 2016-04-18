#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define MaxN 2005
#define REP(i, a, b) for(int i = a; i <= b; i++)

int T, N;

int arr[2505];

int main() {
	ofstream myfile;
	myfile.open("large_output.txt");
	FILE * pFile = fopen("large_input.txt", "r+");

	fscanf(pFile, "%d", &T);

	REP(i, 1, T)
	{
		memset(arr, 0, sizeof(arr));

		fscanf(pFile, "%d", &N);
		int length = (2*N -1)*N-1;
		REP(j, 0, length) {
			int tmp;
			fscanf(pFile, "%d", &tmp);
			arr[tmp]+=1;
		}

		vector<int> result;

		myfile << "Case #" << i << ":" << " ";
		int count = 0;
		REP(k, 0, 2504) {
			if (arr[k] >0 && arr[k]%2 == 1) {
				count++;
				if (count == N) {
					myfile << k;
				} else {
					myfile << k << " ";
				}
			}
		}

		myfile << endl;

	}
	myfile.close();
}
