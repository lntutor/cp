#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
#define Max_N 1001
#define Max_M 1001
#define REP(i, a, b) for (int i = a; i <= b; i++)

int MATRIX[Max_N][Max_M];
int N, M;

struct SKII {
    int length;
    int steepest;
};

SKII getMax(SKII a, SKII b) {
    if (a.length == b.length) {
        return a.steepest > b.steepest ? a : b;
    }
    return a.length > b.length ? a : b;
}

SKII newSkii() {
    SKII result;
    result.length = 0;
    result.steepest = 0;
    return result;
}

SKII dfs(int row, int col) {
    SKII left = newSkii();
    SKII right = newSkii();
    SKII up = newSkii();
    SKII down = newSkii();

    bool canMoveRight = col < M - 1 && MATRIX[row][col] > MATRIX[row][col + 1];
    bool canMoveLeft = col > 0 && MATRIX[row][col] > MATRIX[row][col - 1];
    bool canMoveUp = row > 0 && MATRIX[row][col] > MATRIX[row - 1][col];
    bool canMoveDown = row < N - 1 && MATRIX[row][col] > MATRIX[row + 1][col];

    if (canMoveRight) {
        SKII tmp = dfs(row, col + 1);
        right.length = 1 + tmp.length;
        right.steepest = MATRIX[row][col] - MATRIX[row][col + 1] + tmp.steepest;
    }

    if (canMoveLeft) {
        SKII tmp = dfs(row, col - 1);
        left.length = 1 + tmp.length;
        left.steepest = MATRIX[row][col] - MATRIX[row][col - 1] + tmp.steepest;
    }

    if (canMoveUp) {
        SKII tmp = dfs(row - 1, col);
        up.length = 1 + tmp.length;
        up.steepest = MATRIX[row][col] - MATRIX[row - 1][col] + tmp.steepest;
    }

    if (canMoveDown) {
        SKII tmp = dfs(row + 1, col);
        down.length = 1 + tmp.length;
        down.steepest = MATRIX[row][col] - MATRIX[row + 1][col] + tmp.steepest;
    }

    if (!canMoveLeft && !canMoveRight && !canMoveUp && !canMoveDown) {
        SKII lastBox;
        lastBox.length = 1;
        lastBox.steepest = 0;
        return lastBox;
    }

    return getMax(getMax(left, right), getMax(up, down));
}

SKII solve() {
    SKII result = newSkii();
    REP(i, 0, N - 1) {
        REP(j, 0, M - 1) {
            result = getMax(result, dfs(i, j));
        }
    }
    return result;
}

int main() {

    FILE *pFile = fopen("map.txt", "r+");
    ofstream outputStream;
    outputStream.open("map_output.txt");

    fscanf(pFile, "%d", &N);
    fscanf(pFile, "%d", &M);

    REP(i, 0, N - 1) {
        REP(j, 0, M - 1) {
            fscanf(pFile, "%d", &MATRIX[i][j]);
        }
    }

    SKII result = solve();

    outputStream << result.length << result.steepest << "@redmart.com" << endl;

    outputStream.flush();
    outputStream.close();

    return 1;
}
