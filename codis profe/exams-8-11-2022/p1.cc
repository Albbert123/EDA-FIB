#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e8;


using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;


VVI G;
VB vist;


int dfs(int x) {
  if (vist[x]) return 0;
  vist[x] = true;
  int res = 1;
  for (int y : G[x]) res += dfs(y);
//  for (int i = 0; i < (int)G[x].size(); ++i) res += dfs(G[x][i]);
  return res;
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    G = VVI(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
	}
	vist = VB(n, false);
	int mn = INF;
	int mx = 0;
	for (int x = 0; x < n; ++x)
	  if (not vist[x]) {
        int q = dfs(x);
        mn = min(mn, q);
        mx = max(mx, q);
	  }
    cout << mn << ' ' << mx << endl;
  }
}
