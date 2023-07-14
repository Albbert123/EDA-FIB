// P60796   Tresors en un mapa (2) 
  
  
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


using P = pair<int, int>;
using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;


const VI inc_i = { -1, 1,  0, 0 };
const VI inc_j = {  0, 0, -1, 1 };


int n, m;
VVC M;


void bfs(int i_ini, int j_ini) {
  VVI dist(n, VI(m, -1));
  queue<P> Q;
  dist[i_ini][j_ini] = 0;
  Q.push(P(i_ini, j_ini));
  while (not Q.empty()) {
    P p = Q.front(); Q.pop();
    int i = p.first;
    int j = p.second;
    for (int d = 0; d < 4; ++d) {
      int i2 = i + inc_i[d];
      int j2 = j + inc_j[d];
      if (i2 >= 0 and i2 < n and j2 >= 0 and j2 < m and dist[i2][j2] == -1) {
        dist[i2][j2] = dist[i][j] + 1;
        if (M[i2][j2] == 't') {
          cout << "distancia minima: " << dist[i2][j2] << endl;
          return;
        }
        if (M[i2][j2] == '.') Q.push(P(i2, j2));
      }
    }
  }
  cout << "no es pot arribar a cap tresor" << endl;
}


int main() {
  cin >> n >> m;
  M = VVC(n, VC(m));
  for (int i = 0; i < n; ++i)
    for (char& c : M[i]) cin >> c;
  int i, j;
  cin >> i >> j;
  bfs(i - 1, j - 1);
}
