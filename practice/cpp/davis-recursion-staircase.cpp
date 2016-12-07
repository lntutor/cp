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

#define Max_N 37
int dp[Max_N];

int solve(int n) {
    if (n < 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    if (dp[n-1] == 0) dp[n-1] = solve(n-1);
    if (dp[n-2] == 0) dp[n-2] = solve(n-2);
    if (dp[n-3] == 0) dp[n-3] = solve(n-3);
    return dp[n-1] + dp[n-2] + dp[n-3];
}


int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        printf("%d\n", solve(n));
    }
    return 0;
}
