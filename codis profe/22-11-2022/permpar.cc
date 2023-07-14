// permutacions de paraules


#include <iostream>
#include <vector>
using namespace std;


using VS = vector<string>;
using VI = vector<int>;
using VB = vector<bool>;


int n;
VS par;
VI perm;
VB usat;


void print() {
  for (int i = 0; i < n; ++i) cout << (i ? ',' : '(') << par[perm[i]];
  cout << ')' << endl;
}


void f(int i) {
  if (i == n) return print();

  for (int x = 0; x < n; ++x)
    if (not usat[x]) {
      usat[x] = true;
      perm[i] = x;
      f(i + 1);
      usat[x] = false;
    }
}


int main() {
  cin >> n;
  par = VS(n);
  for (string& s : par) cin >> s;
  perm = VI(n);
  usat = VB(n, false);
  f(0);
}
