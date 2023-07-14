#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int main() {
  int n, m;
  cin >> n >> m;
  VVI G(n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
  }
  int ini;
  cin >> ini;

  queue<int> Q;
  VI dist(n, -1);
  Q.push(ini);
  dist[ini] = 0;
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    cout << x << ' ' << dist[x] << endl;
    for (int y : G[x])
      if (dist[y] == -1) {
        dist[y] = dist[x] + 1;
        Q.push(y);
      }
  }
}
