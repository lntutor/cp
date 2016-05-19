#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i, a, b) for(int i = a ; i <=b ; i++)

int T, N;

int main() {
    cin >> T;

    while(T > 0) {
        cin >> N;
        long long sum[N];
        long long array[N];
        REP(i, 0, N-1) {
            cin >> array[i];
            if (i > 0) sum[i] = sum[i-1] + array[i];
            else {
                sum[i] = array[i];
            }
        }
        bool found = false;
        if (N == 1 || N == 0) {
            found = true;
        }
        REP(i, 1, N-2) {
            if (sum[i-1] == sum[N-1] - sum[i]) {
                found = true;
                break;
            }
        }

        if (found == true) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        T--;
    }
    return 0;
}
