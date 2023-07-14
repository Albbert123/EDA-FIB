#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

bool pos_ok (const vector<vector<char>>& T, int f, int c) {
  return f >= 0 and c >=0 and f < int(T.size()) and c < int(T[0].size());
}

void dfs (vector<vector<char>>& T, int f, int c, char lletra) {
  if (T[f][c] == '.') {
    T[f][c] = lletra;
    for (auto& d : dirs){
      int nf = f+d.first;
      int nc = c+d.second;
      if (pos_ok(T,nf,nc)) dfs(T,nf,nc,lletra);
    }
  }
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<char>> T(n,vector<char>(m));
    vector<pair<int,int>> inicials;
    // Llegeixo
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
	cin >> T[i][j];
	if (T[i][j] != '.' and T[i][j] != '#') inicials.push_back({i,j});
      }    
    
    // Pinto tauler
    for (auto p :  inicials) {
      // DFS des de p
      int f = p.first;
      int c = p.second;
      char lletra = T[f][c];
      T[f][c] = '.';
      dfs(T,f,c,lletra);
    }
    
    // Escric tauler
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	cout << T[i][j];
      }
      cout << endl;
    }
    cout << endl;
  } // Acabo cas
}
