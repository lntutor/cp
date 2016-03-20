//410 Station Balance

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define REP(i, a, b) \
	for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
		for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
		for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
		for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
typedef vector<int> vi;
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

int T;
int N;

int main() {
	int C, S;
	while (scanf("%d", &C) != EOF) {
		scanf("%d", &S);
		int arr[2 * C];
		int cArray[C];
		memset(arr, 0, sizeof(arr));
		memset(arr, 0, sizeof(cArray));

		REP(i, 0, S-1)
		{
			scanf("%d", &arr[i]);
		}

		sort(arr, arr + 2 * C);

		int sum = 0;
		REP(i, 0, C-1)
		{
			cArray[i] = arr[i] + arr[2 * C - i - 1];
			sum += cArray[i];
		}

		int average = sum / C;

		int imBalance = 0;
		REP(i, 0, C-1)
		{
			imBalance += abs(average - cArray[i]);
		}
		cout << imBalance << endl;

	}

	return 0;
}
