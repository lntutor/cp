#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int killed[1024][1024];
int array[1024][1024];

typedef pair<int, int> pi;
typedef vector<pi> vpi;

vpi ratPopulation(0);
int n, d;

int getNumOfRatsKill(int x, int y) {
	int top = max(0, abs(y-d));
	int left = max(0, abs(x-d));

	int right = min(1023, x+d);
	int bottom = min(1023, y+d);
	int result = 0;
	REP(i, top, bottom) {
			REP(j, left, right) {
				result += array[i][j];
			}
		}
	return result;
}

void calKilled(int x, int y) {//cal num of rats get killed when place bombs at squares which center is x,y and radius = d
	int top = max(0, abs(y-d));
	int left = max(0, abs(x-d));

	int right = min(1023, x+d);
	int bottom = min(1023, y+d);
	REP(i, top, bottom) {
		REP(j, left, right) {
			killed[i][j] = getNumOfRatsKill(i, j);
		}
	}
}

void solve() {
	for (vpi::iterator pos = ratPopulation.begin(); pos != ratPopulation.end(); ++pos) {
		int x = pos->first;
		int y = pos->second;
		calKilled(x, y);
	}
	int max = -1;
	REP(i, 0, 1023) {
		REP(j, 0, 1023) {
			if (max < killed[i][j]) max = killed[i][j];
		}
	}
	cout << max << endl;
}

int main() {
	int testCase, x, y, size;
	scanf("%d", &testCase);
	while(testCase>0) {
		ratPopulation.resize(0);
		scanf("%d", &d);
		scanf("%d", &n);
		while(n>0) {
			scanf("%d %d %d", &x, &y, &size);
			ratPopulation.push_back(make_pair(x,y));
			array[x][y] = size;
			n--;
		}
		solve();
		testCase--;
	}
	return 0;
}
