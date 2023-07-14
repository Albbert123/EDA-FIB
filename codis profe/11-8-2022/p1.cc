// P12887   Minimum spanning trees 


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VB = vector<bool>;


int main() {
  int n, m;
  while (cin >> n >> m) {
    VVP G(n);
    while (m--) {
      int x, y, c;
      cin >> x >> y >> c; --x; --y;
      G[x].push_back(P(c, y));
      G[y].push_back(P(c, x));
    }

    VB usat(n, false);
    priority_queue<P> Q;
    Q.push(P(0, 0));
    int res = 0;
    int q = 0;
    while (q < n) {
      P p = Q.top(); Q.pop();
      int c = -p.first;
      int x = p.second;
      if (not usat[x]) {
        ++q;
        usat[x] = true;
        res += c;
        for (P a : G[x]) Q.push(P(-a.first, a.second));
      }
    }
    cout << res << endl;
  }
}
