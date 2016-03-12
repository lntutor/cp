#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 110
#define REP(i, a, b) for(int i = a; i <= b; i++)

int G[MAX][MAX], color[MAX], ans[MAX];
int n, k, _max;

void Creat_Graph() {
	int i = 0, a = 0, b = 0;
	cin >> n >> k;
	for (i = 0; i < k; i++) {
		cin >> a >> b;
		G[a][b] = 1, G[b][a] = 1;
	}
}

int isValid(int cur) {
	for (int i = 1; i <= n; i++) {
		if (G[cur][i] && color[i] == 1)
			return 0;
	}
	return 1;
}

int RESULT = 0;

void backtrack(int cur) {
	if (cur > n) {
		int count = 0;
		REP(i, 1, n)
		{
			if (color[i] == 1)
				count++;
		}
		if (count > RESULT) {
			RESULT = count;
			memset(ans, 0, sizeof(ans));
			REP(j, 1, n)
			{
				if (color[j])
					ans[j] = 1;
			}

		}
		return;
	}

	color[cur] = 0;
	backtrack(cur + 1);
	color[cur] = 1;
	if (isValid(cur))
		backtrack(cur + 1);
	color[cur] = 0;

}

int main() {
	int t = 0, i = 0;
	cin >> t;
	while (t--) {
		memset(G, 0, sizeof(G));
		memset(color, 0, sizeof(color));
		memset(ans, 0, sizeof(ans));
		_max = 0;
		Creat_Graph();
		backtrack(1);
		cout << RESULT << endl;

		REP(i, 1, n)
		{
			if (ans[i] == 1)
				cout << i << endl;
		}
		cout << endl;
	}
}
