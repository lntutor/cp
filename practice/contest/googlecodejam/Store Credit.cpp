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
#define REP(i, a, b) for(int i = a; i <= b; i++)

int t, n, c;
int array[MaxN];
int maxSum = 0;
int selectedI = 0;
int selectedJ = 0;

void solve() {
	REP(i, 0, n-2)
	{
		REP(j, i+1, n-1)
		{
			int sum = array[i] + array[j];
			if (sum <= c && maxSum < sum) {
				maxSum = sum;
				selectedI = i;
				selectedJ = j;
			}
		}
	}

}

int main() {
	ofstream myfile;
	myfile.open("large_output.txt");
	FILE * pFile = fopen("large_input.txt", "r+");

	fscanf(pFile, "%d", &t);

	REP(i, 1, t)
	{
		maxSum = 0;
		fscanf(pFile, "%d", &c);
		fscanf(pFile, "%d", &n);
		REP(j, 0, n-1)
			fscanf(pFile, "%d", &array[j]);
		solve();
		myfile << "Case #" << i << ":" << " " << selectedI + 1 << " " << selectedJ + 1 << endl;

	}
	myfile.close();
}
