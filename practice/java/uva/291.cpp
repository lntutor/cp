#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef pair<int, int> ii;
typedef vector<ii> vii;

int AdjMax[5][5];
vii runningResult;
int totalCount = 0;
void printResult() ;

void removeEdge(int a, int b) {
	for (vii::iterator it = runningResult.begin(); it < runningResult.end();
			it++) {
		int first = it->first;
		int second = it->second;
		if (first == a && second == b) {
			runningResult.erase(it);
			return;
		}
	}
}

bool checkValidEdge(int a, int b) {
	if (runningResult.size() == 0)
		return true;
	for (vii::iterator it = runningResult.begin(); it < runningResult.end();
			it++) {
		int first = it->first;
		int second = it->second;
		if ((first == a && second == b) || (first == b && second == a)) {
			return false;
		}
	}
	return true;
}

void printResult() {

	for (vii::iterator it = runningResult.begin(); it < runningResult.end();
			it++) {
		if (it == runningResult.end() - 1)
			printf("%d%d", it->first + 1, it->second + 1);
		else
			printf("%d", it->first + 1);
	}
	printf("\n");
}

void backtrack(int vertex) {
	if (runningResult.size() == 8) {
		totalCount++;
		printResult();
	}

	REP(i, 0, 4)
	{

		if (AdjMax[vertex][i] && vertex != i) {
			if (checkValidEdge(vertex, i) && vertex != i) {
				runningResult.push_back(ii(vertex, i));

				backtrack(i);
				removeEdge(vertex, i);
			}
		}
	}
}

int main() {
	AdjMax[0][1] = 1;
	AdjMax[1][0] = 1;

	AdjMax[0][2] = 1;
	AdjMax[2][0] = 1;

	AdjMax[0][4] = 1;
	AdjMax[4][0] = 1;

	AdjMax[1][4] = 1;
	AdjMax[4][1] = 1;

	AdjMax[1][2] = 1;
	AdjMax[2][1] = 1;

	AdjMax[2][3] = 1;
	AdjMax[3][2] = 1;

	AdjMax[2][4] = 1;
	AdjMax[4][2] = 1;

	AdjMax[3][4] = 1;
	AdjMax[4][3] = 1;

	backtrack(0);
	return 0;
}
