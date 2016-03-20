#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int MAX_NODE;


//search from 1 to MAX_NODE-1
void BinarySearch(int node, int balls) {
	int left = 2 * node;
	int right = 2 * node + 1;
	if (left < MAX_NODE && right < MAX_NODE) {
		if (balls % 2 == 0) {
			BinarySearch(right, balls / 2);
      // if balls is even, then state of node is True
      // ==> pass the ball to right node, and continue calculate with balls/2
		} else {
    // if balls is odd, then state of node is False
    // ==> pass the ball to left node, and continue calculate with balls/2 + 1
			BinarySearch(left, balls / 2 + 1);
		}
	} else {
		cout << node << endl;
	}
}

int main() {
	int T, D, I;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &D, &I);
		MAX_NODE = pow(2.0, D);
		BinarySearch(1, I);
	}
	return 0;
}
