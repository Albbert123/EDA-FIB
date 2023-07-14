#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e8;


vector<vector<int>> G;
vector<bool> vist;


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
    G = vector<vector<int>>(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
	}
	vist = vector<bool>(n, false);
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