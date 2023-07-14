// P39586   Weighted shortest path (4) 


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;


int n;
VVP G;
int ini, fi;


void dijkstra() {
  priority_queue<P> Q;
  VI dist(n, 1e9);
  VI maneres(n);
  Q.push(P(0, ini));
  dist[ini] = 0;
  maneres[ini] = 1;
  while (not Q.empty()) {
    P p = Q.top(); Q.pop();
    int d = -p.first;
    int x = p.second;
    if (d == dist[x]) {
      if (x == fi) {
        cout << "cost " << d << ", " << maneres[fi] << " way(s)" << endl;
        return;
      }
      for (P arc : G[x]) {
        int d2 = d + arc.first;
        int y = arc.second;
        if (d2 < dist[y]) {
          dist[y] = d2;
          maneres[y] = maneres[x];
          Q.push(P(-d2, y));
        }
        else if (d2 == dist[y]) maneres[y] += maneres[x];
      }
    }
  }
  cout << "no path from " << ini << " to " << fi << endl;
}


int main() {
  int m;
  while (cin >> n >> m) {
    G = VVP(n);
    while (m--) {
      int x, y, c;
      cin >> x >> y >> c;
      G[x].push_back(P(c, y));
    }
    cin >> ini >> fi;
    dijkstra();
  }
}
