#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

bool checkValidNumber(int n, int m) {// check all digits are different each other

	vector<int> array(0);
	while(n > 0) {
		array.push_back(n % 10);
		n = n/10;
	}
	while(m > 0) {
		array.push_back(m % 10);
		m = m/10;
	}

	sort(array.begin(), array.end());
	REP(i, 0, array.size()-2) {
		if(array[i] == array[i+1]) return false;
	}
	return true;
}

bool checkValidNumber(int n) {// check all digits are different each other
	return checkValidNumber(n, 0);
}

void solve(int n) {
	bool found = false;
	REP(i, 1234, 98765) {
		if (!checkValidNumber(i)) continue;
		int tmp = i*n;
		if (!checkValidNumber(tmp)) continue;

		if (tmp <= 98765 && checkValidNumber(i, tmp)){
			printf("%05d / %05d = %d\n", tmp, i, n);
			found = true;
		}
	}

	if (!found) {
		printf("There are no solutions for %d.\n", n);
	}
	return;
}

int main() {
	int n;
	// REP(n, 2, 79)
	// 	solve(n);
	while (true) {
		scanf("%d", &n);
		if (n == 0) return 1;
		solve(n);

	}
	return 0;
}
