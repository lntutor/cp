#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
#define REP(i, a, b) for(int i = a; i <= b; i++)

#define MaxN 10005

int arrN[MaxN];
int arrM[MaxN];
int N, M;


int main() {
    cin >> N;
    REP(i, 0, N-1) {
        int tmp;
        cin >> tmp;
        arrN[tmp]++;
    }

    cin >> M;
    REP(i, 0, M-1) {
        int tmp;
        cin >> tmp;
        arrM[tmp]++;
    }

    REP(i, 0, MaxN-1) {
        if (arrN[i] != arrM[i]) cout << i << " ";
    }

}
