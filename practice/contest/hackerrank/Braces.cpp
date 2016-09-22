https://www.hackerrank.com/contests/test-contest-27/challenges/matching-brackets
#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

bool match(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '{' && b == '}') return true;
    if (a == '[' && b == ']') return true;
    return false;
}

bool isCloseChar(char a) {
    return a == ')' || a == ']' || a == '}';
}
bool solve(string value) {
    std::stack<char> myStack;
    for(int i = 0; i < value.length(); i++) {
        if (myStack.empty() && isCloseChar(value[i])) return false;
        if (value[i] == '(' || value[i] == '{' || value[i] == '[') {
            myStack.push(value[i]);
        } else if (!myStack.empty() && match(myStack.top(),value[i])) myStack.pop();
    }
    if (!myStack.empty()) return false;
    return true;
}

int T;

int main() {
    cin >> T;
    string line;
    while (T > 0) {
        cin >> line;
        if (solve(line)) cout << "YES" << endl;
        else cout << "NO" << endl;
        T--;
    }
    return 0;
}
