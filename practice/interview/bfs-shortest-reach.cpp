#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ii pair<int, int>
#define vii vector<ii>

#define TRvii(c, it) for(vii::iterator it = c.begin(); it != c.end(); it++)

// 2
// 4 2
// 1 2
// 1 3
// 1
// 3 1
// 2 3
// 2


void bfs(vii* adjList, int start) {

  map<int, int> dist;
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    TRvii(adjList[u], v) {
      if (!dist.count(v->first)) {
        dist[v->first] = 1 + dist[v];
        q.push(v->first);
      }
    }
  }
}

int main() {
    int queries;
    cin >> queries;
    vii * adjList;
    for (int t = 0; t < queries; t++) {
      int n, m;
      cin >> n >> m;
      adjList.assign(n, vii());


    }

    return 0;
}
