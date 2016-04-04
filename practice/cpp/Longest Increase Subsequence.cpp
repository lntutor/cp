#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int hello [] = {-7, 10, 9, 2, 3, 8, 8, 1};
int N = 8;
int LIS[8];

int lis(int index) {

	int count = 1;
	for(int i = 0; i < index; i++) {
		if (hello[i] < hello[index]) count++;
	}
	return count;
}

int solve() {
	int max = 0;
	for(int i = 0; i < N; i++) {
		if (LIS[i]==0) LIS[i] = lis(i);
		if (LIS[i] > max) max = LIS[i];
	}
	return max;
}

int main() {
	cout << solve() << endl;
}
