#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i, a, b) for (int i = a; i <= b; i++)

int T;
int nth;
int size;

long long fac(int n) {
	if (n <= 1) return 1;
	else return n*fac(n-1);
}


vector<int> getNthPerm(vector<int> numbers, int nth) {
	int size = numbers.size();
	vector<int> result;

	while(nth > 0) {
		long long tmp = fac(size-1);
		long long number = (int) nth/tmp;

		result.push_back(numbers[number]);
		numbers.erase(numbers.begin() + number);
		size--;

		nth = nth % tmp;
	}

	for(int i = 0; i < numbers.size(); i++) {
		result.push_back(numbers[i]);
	}

	return result;
}

void solve(int size, int nth) {
    vector<int> numbers;
	REP(i, 1, size) numbers.push_back(i);
    vector<int> perm = getNthPerm(numbers, nth);

    int delta = abs(numbers[0] - perm[0]);
    REP(i, 1, size - 1) {
        if (abs(numbers[i] - perm[i]) != delta) {
            cout << -1 << endl;
            return;
        }
    }
    REP(i, 0, size -1) cout << perm[i] << " ";
    cout << endl;

}

int main() {
    cin >> T;
    while(T--) {
        cin >> size;
        cin >> nth;
        solve(size, nth);
    }
    return 0;
}
