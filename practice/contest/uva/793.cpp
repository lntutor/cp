#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int parent[1000];
int myRank[1000];

void makeSet(int x) {
	parent[x] = x;
	myRank[x] = 0;
}

int Find(int i) {
	return parent[i] == i ? i : Find(parent[i]);
}

bool IsSameSet(int i, int j) {
	return Find(i) == Find(j);
}

void Union(int x, int y) {
	int PX = Find(x);
	int PY = Find(y);

	if (PX != PY) {
		if (myRank[PX] > myRank[PY]) {
			parent[PY] = PX;
		} else {
			parent[PX] = PY;
			if (myRank[PX] == myRank[PY]) {
				myRank[PY]++;
			}
		}
	}
}

int main() {
	int T, n;
	string s;
	scanf("%d", &T);
	int x, y;
	char c;

	while (T > 0) {
		scanf("\n%d\n",&n);
		parent[n];
		myRank[n];
		REP(i, 0, n-1)
			makeSet(i);
		vii questionVector(0);

		int success = 0;
		int fail = 0;
		while (true) {
			if (!getline(cin, s) || s.empty())
				break;
			sscanf(s.c_str(), "%c %d %d", &c, &x, &y);
			x--;
			y--;
			if (c == 'c') {
				if (Find(x) != Find(y))
					Union(x, y);
			}
            else IsSameSet(x, y) ? success++:fail++;
		}
		printf("%d,%d\n\n", success, fail);
		T--;
	}
	return 0;
}
