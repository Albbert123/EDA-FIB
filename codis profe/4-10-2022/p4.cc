#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


VI V;


void mergesort(int e, int d) {
  int n = d - e + 1;
  if (n <= 1) return;
  int m = (e + d)/2;
  mergesort(e, m);
  mergesort(m + 1, d);

  VI B(n);
  int i = e;
  int j = m + 1;
  int k = 0;
  while (i <= m and j <= d) {
    if (V[i] <= V[j]) {
      B[k] = V[i];
      ++k;
      ++i;
    }
    else {
      B[k] = V[j];
      ++k;
      ++j;
    }
  }
  while (i <= m) {
    B[k] = V[i];
    ++k;
    ++i;
  }
  while (j <= d) {
    B[k] = V[j];
    ++k;
    ++j;
  }
  for (int z = 0; z < n; ++z) V[e+z] = B[z];
}


int main() {
  int n;
  while (cin >> n) {
    V = VI(n);
    for (int& x : V) cin >> x;
    mergesort(0, n - 1);
    for (int x : V) cout << ' ' << x;
    cout << endl;
  }
}
