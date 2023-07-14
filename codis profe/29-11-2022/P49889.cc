// P49889


#include <iostream>
#include <vector>
using namespace std;


using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;


int n;
VVC M;
VVI perm;
VVB usat;


void escriu() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 2; ++j) cout << M[j][perm[j][i]];
  cout << endl;
}


void f(int i) {
  if (i == 2*n) return escriu();

  int j = i%2;
  for (int x = 0; x < n; ++x)
    if (not usat[j][x]) {
      usat[j][x] = true;
      perm[j][i/2] = x;
      f(i + 1);
      usat[j][x] = false;
	}
}


int main() {
  cin >> n;
  M = VVC(2, VC(n));
  for (int j = 0; j < 2; ++j)
    for (char& c : M[j]) cin >> c;
  perm = VVI(2, VI(n));
  usat = VVB(2, VB(n, false));
  f(0);
}
