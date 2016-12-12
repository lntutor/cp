//https://www.hackerrank.com/challenges/ctci-contacts/submissions/code/33775265
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

typedef map<string, int> msi;

msi dictionary;

int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "find") {
          cout << dictionary[contact] << endl;
        } else {
          //cout << "contact = " << contact << endl;
          for(int i = 0; i < contact.size(); i++) {
            string tmp = contact.substr(0, i + 1);
            //cout << "tmp = " << tmp << endl;
            dictionary[tmp]++;
          }
        }
    }
    return 0;
}
