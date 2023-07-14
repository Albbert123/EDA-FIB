// Escriu totes les permutacions.


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int n;
VI perm;
VB usat;


void escriu() { 
  for (int x : perm) cout << ' ' << x;
  cout << endl;
}


void f(int i) {
  if (i == n) return escriu();

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
  perm = VI(n);
  usat = VB(n, false);
  f(0);
}
