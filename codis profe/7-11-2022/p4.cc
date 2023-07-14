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
  int ini, fi;
  cin >> ini >> fi;

  queue<int> Q;
  VI vist(n, false);
  VI pare(n);
  Q.push(ini);
  vist[ini] = true;
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y : G[x])
      if (not vist[y]) {
        vist[y] = true;
        pare[y] = x;
        Q.push(y);
        if (y == fi) {
          VI V;
          while (y != ini) {
            V.push_back(y);
            y = pare[y];
          }
          cout << ini;
          for (int i = V.size() - 1; i >= 0; --i)
            cout << ' ' << V[i];
          cout << endl;
        }
      }
  }
}
