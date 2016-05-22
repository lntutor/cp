#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = a; i <= b; i++)

void swap(char* a, char* b) {
	char *tmp = a;
	*a = *b;
	*b = *tmp;
}

void permutation(char* number, int left, int right) {
	if (left == right) {
		cout << number << endl;
		return;
	}

	REP(i, left, right) {
		swap(number[left], number[i]);
		permutation(number, left + 1, right);
		swap(number[left], number[i]);
	}
}
int main() {
	char str[] = "ABCDEF";
	permutation(str, 0, sizeof(str)/sizeof(char) - 2);
	return 0;
}
