#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <set>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int N = 1e5;
int n = 11;
int t[2 * N];
int value[2 * N];
vii boundaries;

int array[N];

int tree_query(int l, int r);

void build() {
	for (int i = n - 1; i > 0; --i) {
		t[i] = max(t[i << 1], t[i << 1 | 1]);
	}
}

int query(int l, int r) {
	if (l == 0 && r == n - 1) {
		return tree_query(l, r);
	}

	if (l + 1 == r && array[l] != array[r])
		return 1;

	if (l + 1 == r && array[l] == array[r])
		return 2;

	int partialLeft = 0;
	for (vii::iterator it = boundaries.begin(); it != boundaries.end(); it++) {
		int left = it->first;
		int right = it->second;
		if (l > r)
			break;
		if (right != left) {
			if (left == l)
				break;
			if (l > left && l <= right) {
				partialLeft = right - l + 1;
				break;
			}
		}
	}

	int partialRight = 0;
	for (vii::iterator it = boundaries.end(); it != boundaries.begin(); it--) {
		int left = it->first;
		int right = it->second;
		if (right != left) {
			if (right == r)
				break;
			if (l >= left && l <= right) {
				partialRight = r - left + 1;
				break;
			}
		}
	}
	int maxPartial = max(partialLeft, partialRight);
	return max(maxPartial, tree_query(l + partialLeft, r - partialRight));
}

int tree_query(int l, int r) {

	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) {
			res = max(res, t[l++]);
		}
		if (r & 1) {
			res = max(t[--r], res);
		}
	}
	return res;
}

int main() {
	n = 10;
	while (true) {
		int numOfQuery = 0;
		scanf("%d", &n);
		if (n == 0)
			return 1;
		scanf("%d", &numOfQuery);
		REP(i, 0, n-1)
		{
			scanf("%d", &array[i]);
		}

		int newArray[n];

		int lastStartIndex = 0;
		int count = 1;

		REP(i, 1, n)
		{

			if (array[i] != array[i - 1] || i == n) {

				REP(j, lastStartIndex, i)
				{
					newArray[j] = count;
				}
				boundaries.push_back(make_pair(lastStartIndex, i - 1));
				lastStartIndex = i;

				count = 1;
			} else {
				count++;
			}

		}

		REP(i, 0, n-1)
		{
			t[i + n] = newArray[i];
		}

		build();

		REP(k, 1, numOfQuery)
		{
			int left, right;
			scanf("%d %d", &left, &right);
			printf("%d\n", query(left - 1, right - 1));

		}
	}
	return 0;
}
