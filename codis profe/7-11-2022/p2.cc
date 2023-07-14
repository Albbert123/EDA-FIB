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
  VI vist(n, false);
  Q.push(ini);
  vist[ini] = true;
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    cout << x << endl;
    for (int y : G[x])
      if (not vist[y]) {
        vist[y] = true;
        Q.push(y);
      }
  }
}
