#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int MAX = 10005;
int OFFSET = 10005;

int parent[10005*2 + 1];
int myRank[10005*2 + 1];

void setEnemies(int x, int y);
void setFriends(int x, int y);

void makeSet(int x) {
	parent[x] = x;
	myRank[x] = 0;
}

int Find(int i) {
	return parent[i] == i ? i : Find(parent[i]);
}

void Merge(int x, int y) {
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

void setFriends(int x, int y) {
	Merge(x, y);
	Merge(OFFSET + x, OFFSET + y);
}

void setEnemies(int x, int y) {
	Merge(x, OFFSET + y);
	Merge(OFFSET + x, y);
}

bool areEnemies(int x, int y) {
	return Find(x) == Find(OFFSET + y) || Find(OFFSET + x) == Find(y);
}

bool areFriends(int x, int y) {
	return Find(x) == Find(y) || Find(OFFSET + x) == Find(OFFSET + y);
}

int main() {
	int n;
	scanf("%d\n", &n);

	REP(i, 0, 2*MAX)
		makeSet(i);
	cout << endl;
	while (true) {
		int q, a, b;
		scanf("%d %d %d", &q, &a, &b);
		if (a == 0 && b == 0 && q == 0)
			break;

		if (q == 1) {
			if (areEnemies(a, b)) {
				cout << -1 << endl;
			} else {
				setFriends(a, b);
			}

		} else if (q == 2) {
			if (areFriends(a, b)) {
				cout << -1 << endl;
			} else {
				setEnemies(a, b);
			}
		} else if (q == 3) {
			int result = areFriends(a, b) ? 1 : 0;
			cout << result << endl;
		} else {
			int result = areEnemies(a, b) ? 1 : 0;
			cout << result << endl;
		}
	}
	return 0;
}
