#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define REP(i, a, b) for (int i = a; i <= b; i++)

int T, N, M;

set<long long> myset;

int main() {

	cin >> T;
	while (T--) {
		cin >> N;
		cin >> M;
		long long array[N];
		long long prefix[N];
		memset(array, 0, sizeof(array));
		memset(array, 0, sizeof(prefix));
		for (int i = 0; i < N; i++) {
			if (i == 0)
				cin >> array[i];
			else {
				long long tmp;
				cin >> tmp;
				array[i] = tmp + array[i - 1];
			}
		}

		REP(i, 0, N-1)
		{
			prefix[i] = array[i] % M;
		}

		long long MAX = 0;
		myset.insert(prefix[0]);
		MAX = 0;
		REP(i, 0, N - 1)
		{
			MAX = max (prefix[i], MAX);
			std::set<long long>::iterator it = myset.lower_bound(prefix[i] + 1);
			if (it != myset.end()) {
				MAX = max(MAX, prefix[i] - *it + M);
			}
			myset.insert(prefix[i]);

		}
		cout << MAX << endl;
	}
	return 0;
}
