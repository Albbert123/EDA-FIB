#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;


int main() {
  int n, m;
  cin >> n >> m;
  VVP G(n);
  while (m--) {
    int x, y, c;
    cin >> x >> y >> c;
    G[x].push_back(P(c, y));
  }
  int ini, fi;
  cin >> ini >> fi;

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
        return 0;
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
}
