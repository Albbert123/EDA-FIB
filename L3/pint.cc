#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

bool pos_ok (const vector<vector<char>>& T, int f, int c) {
  return f >= 0 and c >=0 and f < int(T.size()) and c < int(T[0].size());
}

void dfs (vector<vector<char>>& T, int f, int c, char lletra) {
  if (T[f][c] == '.') {
    T[f][c] = lletra;
    for (int i=0; i<4; ++i){
      int nf = f+dirs[i].first;
      int nc = c+dirs[i].second;
      if (pos_ok(T,nf,nc)) dfs(T,nf,nc,lletra);
    }
  }
}

int main() {
    int n,m;
    while(cin >> n >> m) {
        vector<vector<char>> T(n, vector<char>(m));
        vector<pair<int,int>> inicials;
        //leo
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin >> T[i][j];
                if(T[i][j]!='.' and T[i][j] != '#') inicials.push_back({i,j});
            }
        }

        //pinto tablero
        for(int i=0; i<inicials.size(); ++i) {
            //DFS desde p
            int f = inicials[i].first;
            int c = inicials[i].second;
            char lletra = T[f][c];
            T[f][c] = '.';
            dfs(T,f,c,lletra);
        }

        //escribir
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cout << T[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}