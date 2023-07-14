// Prim


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


const int INF = 1e8;


using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VB = vector<bool>;


int main() {
  int n, m;
  cin >> n >> m;
  VVP G(n);
  while (m--) {
    int x, y, c;
    cin >> x >> y >> c;
    G[x].push_back(P(c, y));
    G[y].push_back(P(c, x));
  }

  int res = 0;
  int q = 0;
  VB usat(n, false);
  priority_queue<P, vector<P>, greater<P>> Q;
  Q.push(P(0, 0));
  while (q < n) {
    P p = Q.top(); Q.pop();
    int c = p.first;
    int x = p.second;
    if (not usat[x]) {
      usat[x] = true;
      res += c;
      ++q;
      for (P a : G[x]) Q.push(a);
    }
  }
  cout << res << endl;
}
