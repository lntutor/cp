#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
#define Max_N 100
#define REP(i, a, b) for (int i = a; i <=b; i++)
int T, N;

char matrix[Max_N][Max_N];

bool checkMatrix() {

    REP(i, 0, N - 1) {
        REP(j, 0, N - 2) {
            if (matrix[i][j] > matrix[i][j + 1]) return false;
        }
    }

    REP(i, 0, N - 2) {
        REP(j, 0, N - 1) {
            if (matrix[i][j] > matrix[i + 1][j]) return false;
        }
    }
    return true;
}

int main() {

    cin >> T;
    while (T > 0) {
        memset(matrix, 0, sizeof(matrix));
        cin >> N;

        REP(i, 0, N - 1) {
            REP(j, 0, N - 1) {
                cin >> matrix[i][j];
            }
            sort(matrix[i], matrix[i] + N);
        }

        if (checkMatrix()) cout << "YES" << endl;
        else cout << "NO" << endl;
        T--;
    }
    return 0;
}
