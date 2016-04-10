#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define REP(i, a, b) for(int i = a; i <=b ; i++)

int N, K, Q;

std::vector<int> myQueue;


int main() {
    cin >> N;
    cin >> K;
    cin >> Q;
    REP(i, 0, N-1){
        int tmp;
        cin >> tmp;
        myQueue.push_back(tmp);
    }

    while(K>0) {
        int end = *(myQueue.end() - 1);
        myQueue.erase(myQueue.end() - 1);
        myQueue.insert(myQueue.begin(), end);
    }

    while(Q-->0) {
        int tmp;
        cin >> tmp;
        cout << myQueue[tmp] << endl;
    }

    return 0;
}
