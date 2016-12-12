#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)


#define DEFAULT_WEIGHT 1
#define DFS_BLACK 1
#define DFS_WHITE 0
#define V 100

int visitedNodes[V];
vii adjList [V];

void dfs(int u) {
    printf("%d", u);
    visitedNodes[u] = DFS_BLACK;
    TRvii(adjList[u], v) {
        if (visitedNodes[v->first] == DFS_WHITE) {
            dfs(v->first);
        }
    }
}

void getConnectedComponent() {
    int numOfComponent = 0;
    memset(visitedNodes, DFS_WHITE, sizeof visitedNodes);
    REP(i, 0, V-1) {
        if (visitedNodes[i] == DFS_WHITE) {
            dfs(i);
            numOfComponent++;
        }
    }
    cout << "Num of connected component :" << numOfComponent << endl;
}


queue<int> q;
map<int, int> dist;

void bfs(int s) {
    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        printf("Visit %d, Layer %d\n", u, dist[u]);
        TRvii(adjList[u], v) {
            if (!dist.count(v->first)) {
                dist[v->first] = dist[u] + 1;
                q.push(v->first);
            }
        }
    }
}

int main()
{
    adjList[0].push_back(make_pair(1 , DEFAULT_WEIGHT));
    adjList[1].push_back(make_pair(0 , DEFAULT_WEIGHT));
    adjList[1].push_back(make_pair(2 , DEFAULT_WEIGHT));
    adjList[2].push_back(make_pair(1 , DEFAULT_WEIGHT));
    adjList[2].push_back(make_pair(3 , DEFAULT_WEIGHT));
    adjList[3].push_back(make_pair(4 , DEFAULT_WEIGHT));
    adjList[4].push_back(make_pair(3 , DEFAULT_WEIGHT));
    adjList[6].push_back(make_pair(7 , DEFAULT_WEIGHT));
    adjList[7].push_back(make_pair(6 , DEFAULT_WEIGHT));

    dfs(1);
//    getConnectedComponent();

    return 1;
}
