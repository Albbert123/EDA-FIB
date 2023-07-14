#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> G;
vector<bool> vist;

void dfs(int x, int& v, int& a) {
  if (vist[x]) return;
  vist[x] = true;
  ++v;
  a += G[x].size();
  //for (int y : G[x]) dfs(y, v, a);
  for (int i = 0; i < (int)G[x].size(); ++i) dfs(G[x][i], v, a);
}


void bosc() {
  vist = vector<bool> (n, false);
  int q = 0;
  for (int x = 0; x < n; ++x) {
    if (not vist[x]) {
      int v = 0, a = 0;
      dfs(x, v, a);
      if (a != 2*(v - 1)) { //?
        cout << "no" << endl;
        return;
      }
      ++q;
    }
  }
  cout << q << endl;
}


int main() {
  int m;
  while (cin >> n >> m) {
    G = vector<vector<int>>(n);
    for(int i=0; i<m; ++i) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    bosc();
  }
}
