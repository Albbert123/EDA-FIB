#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

bool pos_ok (const vector<vector<char>>& T, int f, int c) {
  // if (f >= 0 and f < T.size() and c >= 0 and c < T[0].size()) return true;
  // else return false;
  return (f >= 0 and f < T.size() and c >= 0 and c < T[0].size());
}
// DFS recursiu
bool tresor (vector<vector<char>>& T, int f_ini, int c_ini) {
  if (T[f_ini][c_ini] == 'X') return false;
  if (T[f_ini][c_ini] == 't') return true;
  T[f_ini][c_ini] = 'X';

  for (auto d : dirs) {
    int n_f = f_ini + d.first;
    int n_c = c_ini + d.second;
    if (pos_ok(T,n_f,n_c) and tresor(T,n_f,n_c)) return true;
  }
  return false;
}

int main(){
  // Llegeixo entrada
  int f, c;
  cin >> f >> c;
  vector<vector<char>> T(f,vector<char>(c));
  for (int i = 0; i < f; ++i)
    for (int j = 0; j < c; ++j)
      cin >> T[i][j];
  int f_ini, c_ini;
  cin >> f_ini >> c_ini;

  // Calculo arribabilitat
  if (tresor(T, f_ini - 1, c_ini - 1)) cout << "yes" << endl;
  else cout << "no" << endl;
}
