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

#define REP(i, a, b) for(int i = a; i <= b; i++)

int number_needed(string a, string b) {
    vector<int> dict(26);
    REP(i, 0, a.length()-1)
        dict[a[i] - 'a']++;

    REP(i, 0, b.length()-1)
        dict[b[i] - 'a']--;

    int result = 0;
    REP(i, 0, dict.size()-1)
        result += abs(dict[i]);
    return result;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
