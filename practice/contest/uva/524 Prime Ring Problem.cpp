#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define REP(i, a, b) for(int i = a; i <= b; i++)

vector<int> result(0);
int n;

bool isExist(int number) {
	for (vector<int>::iterator it = result.begin(); it != result.end(); it++) {
		if (*it == number)
			return true;
	}
	return false;
}

bool isPrime(int n) {
	int squarN = sqrt(n);

	REP(i, 2, squarN)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isValid(int sum, int number) {
	return isPrime(sum) && !isExist(number);
}

void backTrack(int current) {

	if (current > n) {
		REP(i, 0, n-1)
		{
			if (i < n - 1)
				cout << result[i] << " ";
			else
				cout << result[i];
			;
		}
		cout << endl;
		return;
	}

	REP(i, 1, n)
	{
		if (result.size() <= n - 1) {
			int last = *(result.end() - 1);
			if (isValid(last + i, i)) {
				result.push_back(i);
				backTrack(current + 1);
				result.pop_back();
			}
		} else {
			int last = *(result.end() - 1);
			int first = *(result.begin());
			if (isValid(last + i, i) && isValid(first + i, i)) {
				result.push_back(i);
				backTrack(current + 1);
				result.pop_back();
			}
		}
	}
}

int main() {
	int t;
	while (scanf("%d", &n) != EOF) {
		result.clear();
		result.push_back(1);

		printf("Case %d:\n", ++t);
		backTrack(2);
	}
}
