// P43859   Weighted shortest path (1) 


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
  Q.push(P(0, ini));
  dist[ini] = 0;
  while (not Q.empty()) {
    P p = Q.top(); Q.pop();
    int d = -p.first;
    int x = p.second;
    if (d == dist[x]) {
      if (x == fi) {
        cout << d << endl;
        return;
      }
      for (P arc : G[x]) {
        int d2 = d + arc.first;
        int y = arc.second;
        if (d2 < dist[y]) {
          dist[y] = d2;
          Q.push(P(-d2, y));
        }
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
