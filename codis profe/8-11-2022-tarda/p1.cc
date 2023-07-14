// P70690   Tresors en un mapa (1) 


#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;


int n, m;
VVC M;
VVB vist;


bool dfs(int i, int j) {
  if (i < 0 or i >= n or j < 0 or j >= m or vist[i][j]) return false;
  vist[i][j] = true;
  if (M[i][j] == 't') return true;
  if (M[i][j] == 'X') return false;
  return dfs(i - 1, j) or dfs(i + 1, j) or dfs(i, j - 1) or dfs(i, j + 1);
}


int main() {
  cin >> n >> m;
  M = VVC(n, VC(m));
  for (int i = 0; i < n; ++i)
    for (char& c : M[i]) cin >> c;
  int i, j;
  cin >> i >> j;
  vist = VVB(n, VB(m, false));
  cout << (dfs(i - 1, j - 1) ? "yes" : "no") << endl;
}
