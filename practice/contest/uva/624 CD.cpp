#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define REP(i, a, b) for(int i = a; i <= b; i++)

vector<int> runningVector(0);
vector<int> resultVector(0);

//int array[] = {10, 5, 7, 4};
//int tapeSize = 20;
//int n = 4;
//int answer = 0;

int array[] = { 10, 23, 1, 2, 3, 4, 5, 7 };
int tapeSize = 90;
int n = 8;
int answer = 0;

int getCurrentSum() {
	int sum = 0;
	for (vector<int>::iterator it = runningVector.begin();
			it != runningVector.end(); it++) {
		sum += *it;
	}
	return sum;
}

bool isExist(int number) {
	for (vector<int>::iterator it = runningVector.begin();
			it != runningVector.end(); it++) {
		if (*it == number)
			return true;
	}
	return false;
}

void copyVector() {
	resultVector.clear();
	for (vector<int>::iterator it = runningVector.begin();
			it != runningVector.end(); it++) {
		resultVector.push_back(*it);
	}
}

bool isValid(int number) {
	return !isExist(number);
}

void bt(int cur) {
	if (cur >= n || getCurrentSum() >= tapeSize) {
		if (getCurrentSum() <= tapeSize) {
			int currentSum = getCurrentSum();
			if (currentSum > answer) {
				answer = currentSum;
				copyVector();
			}
		}
		return;
	}

	REP(i, 0, n-1)
	{
		if (isValid(array[i])) {
			runningVector.push_back(array[i]);
			bt(cur + 1);
			runningVector.pop_back();
		}
	}
}

int main() {

	while (scanf("%d %d", &tapeSize, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &array[i]);
		}

		bt(0);
		for (vector<int>::iterator it = resultVector.begin();
				it != resultVector.end(); it++) {
			cout << *it << " ";
		}
		cout << "sum:" << answer << endl;
	}

}
