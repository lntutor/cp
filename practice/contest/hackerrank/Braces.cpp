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

bool isOpenChar(char a) {
    return a == '(' || a == '[' || a == '{';
}
bool solve(string value) {
    std::stack<char> myStack;
    for(int i = 0; i < value.length(); i++) {
        if (isOpenChar(value[i])) {
            myStack.push(value[i]);
            continue;
        }
        //close char case
        if (myStack.empty()) return false;
        if (match(myStack.top(), value[i])) myStack.pop();
        else false;
    }
    return myStack.empty();
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
