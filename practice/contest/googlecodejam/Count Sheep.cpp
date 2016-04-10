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

int T, N;

int number[10];//0-9 index

long long solve() {//return last number or insomnia if loop forever

	if (N == 0) return -1;
	memset(number, 0, sizeof(number));
	long long tmp = N;
	int count = 1;
	long long currentNumber = tmp;
	while(true) {
		tmp = count*N;
		currentNumber = tmp;
		count++;
		while(tmp>0) {
			int lastNumber = tmp%10;
			number[lastNumber]++;
			tmp = tmp/10;
		}

		bool isSleep = true;
		REP(i, 0, 9) {
			if (number[i] == 0) {
				isSleep = false;
				break;
			}
		}
		if (isSleep == true) return currentNumber;
	}

	return currentNumber;
}

int main() {
	ofstream myfile;
	myfile.open("large_output.txt");
	FILE * pFile = fopen("large_input.txt", "r+");

	fscanf(pFile, "%d", &T);

	REP(i, 1, T)
	{

		fscanf(pFile, "%d", &N);
		long long result = solve();
		if (result == -1)
			myfile << "Case #" << i << ":" << " " << "INSOMNIA" << endl;
		else
			myfile << "Case #" << i << ":" << " " << result << endl;

	}
	myfile.close();
}
