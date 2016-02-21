#include <iostream>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int array[1024][1024];

#define EMPTY 0
#define WALL 1
#define FROOK 2
#define NO_CHOOSE 3
int n;
int res = 0;

bool check(int row, int col) {
	if (array[row][col] == WALL || array[row][col] == FROOK)
		return false;

	bool isColumnOk = true;
	REP(i, 0, n-1)
	{ //check column
		if (array[i][col] == FROOK) {
			bool isWallBetween = false;
			REP(j, 0, n-1)
			{
				if (array[j][col] == WALL && j > i && j < row) {
					isWallBetween = true;
				}
			}
			isColumnOk = isWallBetween;
		}
	}

	bool isRowOk = true;
	REP(i, 0, n-1)
	{ //check row
		if (array[row][i] == FROOK) {
			bool isWallBetween = false;
			REP(j, 0, n-1)
			{
				if (array[row][j] == WALL && j > i && j < col) {
					isWallBetween = true;
				}
			}
			isRowOk = isWallBetween;
		}
	}
	return isColumnOk && isRowOk;
}

void solve(int row, int col, int tmpRes) {
	if (col == n) {
		row++;
		col = 0;
	}

	res = max(res, tmpRes);

	if (row >= n)
		return;

	REP(i, row, n-1)
	{
		REP(j, col, n-1)
		{
			solve(i, j + 1, tmpRes);

			if (check(i, j)) {
				array[i][j] = FROOK;
				solve(i, j + 1, tmpRes + 1);
				array[i][j] = EMPTY;
			}
		}
	}
}

int main() {
	while (true) {
		string line;
		cin >> n;
		if (n == 0)
			break;

		memset(array, sizeof(array), 0);

		REP(i, 0, n-1 )
		{
			cin >> line;
			REP(j, 0, n-1)
			{
				line[j] == '.' ? array[i][j] = EMPTY : array[i][j] = WALL;
			}
		}
		res = 0;
		solve(0, 0, 0);
		cout << res << endl;

	}
	return 0;
}
