// Prim


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VP = vector<P>;
using T = pair<int, P>;
using VB = vector<bool>;


int main() {
  int n, m;
  cin >> n >> m;
  vector<VP> G(n);
  while (m--) {
    int x, y, c;
    cin >> x >> y >> c;
    G[x].push_back(P(c, y));
    G[y].push_back(P(c, x));
  }

  int suma = 0;
  priority_queue<T, vector<T>, greater<T>> Q;
  Q.push(T(0, P(-1, 0)));
  VB usat(n, false);
  int q = 0;
  while (q < n) {
    T a = Q.top(); Q.pop();
    int c = a.first;
    int x = a.second.first;
    int y = a.second.second;
    if (not usat[y]) {
      usat[y] = true;
      ++q;
      if (x != -1) cout << x << ' ' << y << ' ' << c << endl;
      suma += c;
      for (P b : G[y]) Q.push(T(b.first, P(y, b.second)));
    }
  }
  cout << suma << endl;
}
