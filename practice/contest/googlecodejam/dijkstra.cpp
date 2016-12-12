#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
#define TRvii(c, it) for(vii::iterator it = c.begin(); it != c.end(); it++)
#define REP(i, a, b) for (int i = a; i <= b; i++)

int main() {
    int V, E, s, u, v, w;
    vector<vii> AdjList;
    freopen("dijkstra_graph.txt", "r", stdin);
    scanf("%d %d %d", &V, &E, &s);

    AdjList.assign(V, vii());
    REP(i, 0, E-1) {
      scanf("%d %d %d", &u, &v, &w);
      AdjList[u].push_back(ii(v, w));
    }

    vi dist(V, INF);

    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));
    while(!pq.empty()) {
      ii front = pq.top(); pq.pop();
      int distance = front.first;
      int u = front.second;
      //if (distance > dist[u]) continue;
      TRvii(AdjList[u], v) {
        if (dist[u] + v->second < dist[v->first]) {
          dist[v->first] = dist[u] + v->second;
          pq.push(ii(dist[v->first], v->first));
        }
      }
    }

    REP(i, 0, V-1)  printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);

    return 0;
}
