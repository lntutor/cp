#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

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

void Union(int x, int y) { //A > 1
	int PX = Find(x);
	int PY = Find(y);

	if (PX != PY) {
		if (myRank[PX] > myRank[PY]) {
			parent[PY] = PX;
		} else {
			if (PX > PY) {
				parent[PY] = PX;
				if (myRank[PX] == myRank[PY]) {
					myRank[PX]++;
				}
			} else {
				parent[PX] = PY;
				if (myRank[PX] == myRank[PY]) {
					myRank[PY]++;
				}
			}
		}
	}
}

int main() {
	int n;
	string s;

	while (true) {
		scanf("%d\n", &n);
		memset(parent, 0, sizeof parent);
		memset(myRank, 0, sizeof myRank);

		REP(i, 0, 999)
			makeSet(i);
		int firstDNA[n];
		int secondDNA[n];

		REP(i, 0, n-1)
		{
			getline(cin, s);
			firstDNA[i] = s[0];
		}

		REP(i, 0, n-1)
		{
			getline(cin, s);
			secondDNA[i] = s[0];
		}
		vii result(0);
		REP(i, 0, n-1)
		{
			if (firstDNA[i] != secondDNA[i]) {
				Union(firstDNA[i], secondDNA[i]);

				int PX = Find(firstDNA[i]);
				int charToReplace =
						firstDNA[i] < secondDNA[i] ? firstDNA[i] : secondDNA[i];

				REP(j, 0, n-1)
				{
					if (firstDNA[j] == charToReplace) {
						firstDNA[j] = PX;
					}
					if (secondDNA[j] == charToReplace) {
						secondDNA[j] = PX;
					}
				}

				result.push_back(make_pair(charToReplace, PX));

			}
		}

		if (result.size() > 0) {
			printf("YES\n");
			std::sort(result.begin(), result.end());
			for (vii::iterator it = result.begin(); it != result.end(); it++) {
				int first = it->first;
				int second = it->second;
				char W = static_cast<char>(first);
				char Y = static_cast<char>(second);

				printf("%c %c\n", W, Y);

			}
		} else {
			printf("NO\n");
		}
		if (!getline(cin, s) || s.empty()) return 1;
	}
	return 0;
}
