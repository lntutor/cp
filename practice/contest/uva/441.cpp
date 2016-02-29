#include <iostream>
#include <algorithm>

//typedef vector<int> vi;

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int main() {
	while(true) {
		int n;
		scanf("%d", &n);
		if (n==0) break;
		int array [n];
		REP(i, 0, n-1 ) {
			scanf("%d", &array[i]);
		}
		REP(i, 0, n - 6)
			REP(j, i + 1, n - 5)
				REP(k, j + 1, n - 4)
					REP(l, k + 1, n - 3)
						REP(m, l + 1, n - 2)
							REP(t, m + 1, n - 1)
			printf("%d %d %d %d %d %d\n", array[i], array[j], array[k], array[l], array[m], array[t]);



	}
	return 0;
}
