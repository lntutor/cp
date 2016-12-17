#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define MAX_N 100001

bool PRIMES_ARRAY[MAX_N];

bool isPrime(int n) {

    for(int i = 2; i <= n/2; i++) {
        if (n%i==0) return false;
    }
    return true;
}

void sieves() {
  memset(PRIMES_ARRAY, 1, sizeof(PRIMES_ARRAY)/sizeof(PRIMES_ARRAY[0]));
  PRIMES_ARRAY[0] = false;
  PRIMES_ARRAY[1] = false;
  for(int i = 2; i*i < MAX_N; i++) {
    if (isPrime(i)) {
      PRIMES_ARRAY[i] = true;
      for (int j = 2; ; j++) {
          if (i*j > MAX_N) break;
          PRIMES_ARRAY[i*j] = false;
      }
    } else {
        PRIMES_ARRAY[i] == false;
    }
  }

}

int countPrime(int n) {
    int result = 0;
    for (int i = 0; i <=n; i++) {
        if (PRIMES_ARRAY[i] == true) {
            result++;
        }
    }
    return result;
}

void solve(int n) {
    if (n == 1) {
        cout << "Bob" << endl;
        return;
    }
    if (n == 2) {
        cout << "Alice" << endl;
        return;
    }
    int primes = countPrime(n);
    if (primes % 2 == 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}


int main(){
    sieves();
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
