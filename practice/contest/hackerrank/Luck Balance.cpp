//https://www.hackerrank.com/contests/w21/challenges/luck-balance

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, K, L, T;

long long importMatchLuck[100];

int main() {
    long long totalLuck = 0;
    cin >> N >> K;

    int count = 0;
    for (int i = 0; i <N; i++) {
        cin >> L >> T;
        totalLuck += L;
        if (T==1) {
            importMatchLuck[count] = L;
            count++;
        }
    }

    sort(importMatchLuck,importMatchLuck + count);

    int winMatch = count - K;
    for (int i = 0; i < winMatch; i++) {
        totalLuck = totalLuck - 2*importMatchLuck[i];
    }

    cout << totalLuck << endl;
    return 0;
}
