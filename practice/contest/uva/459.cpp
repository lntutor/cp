#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef pair<int, int> ii;
typedef vector<ii> vii;

int parent[26];
int myRank[26];

void makeSet(int x) {
	parent[x] = x;
	myRank[x] = 0;
}

int Find(int i) {
	return parent[i] == i ? i : Find(parent[i]);
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
	scanf("%d\n", &T);
	int x, y;
	int ans;
	while(T>0){
		getline(cin, s);
		n = s[0] - 'A' + 1;
		ans = n;
		REP(i, 0, n-1) makeSet(i);
		while(true) {
			if (!getline(cin, s) || s.empty()) break;
			x = s[0] - 'A';
			y = s[1] - 'B';
			if (Find(x) != Find(y)) {
				Union(x, y);
				ans--;
			}
		}
        printf("%d\n",ans);
		T--;
	}
	return 0;
}
