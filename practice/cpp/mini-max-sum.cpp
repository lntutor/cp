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


int main(){
    long int a;
    long int b;
    long int c;
    long int d;
    long int e;

    cin >> a >> b >> c >> d >> e;
    int arr[5];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    arr[4] = e;

    sort(arr, arr + 5);
    long SUM = a + b + c + d + e;

    cout << SUM - arr[4] << " " << SUM - arr[0] << endl;

    return 0;
}
