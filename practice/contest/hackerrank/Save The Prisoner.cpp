#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M, S;

int solve(int n, int m, int s) {
    int firstCycleRemain = n - s + 1;
    if (m <= firstCycleRemain) return s + m - 1;
    int result = (m - firstCycleRemain) % n;
    if (result == 0) return n;
    return result;
}

int main() {
    cin >> T;
    while (T > 0) {
        cin >> N;
        cin >> M;
        cin >> S;
        cout << solve(N, M, S) << endl;
        T--;
    }
    return 0;
}
