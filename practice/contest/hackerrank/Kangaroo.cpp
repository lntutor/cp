//https://www.hackerrank.com/contests/w21/challenges/kangaroo

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

bool solve(int x1, int v1, int x2, int v2) {
    if (x1 < x2 && v1 <= v2) return false;
    if (x2 < x1 && v2 <= v1) return false;
    int x = abs(x2 - x1);
    int v = abs(v2 - v1);
    return x % v == 0 || v % x == 0;
}


int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;

    if (solve(x1, v1, x2, v2)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
