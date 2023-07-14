#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


VI V;


int mergesort(int e, int d) {
  int n = d - e + 1;
  if (n <= 1) return 0;
  int m = (e + d)/2;
  int res = mergesort(e, m) + mergesort(m + 1, d);

  VI B(n);
  int i = e;
  int j = m + 1;
  int k = 0;
  while (i <= m and j <= d)
    if (V[i] <= V[j]) B[k++] = V[i++];
    else {
      res += m - i + 1;
      B[k++] = V[j++];
    }
  while (i <= m) B[k++] = V[i++];
  while (j <= d) B[k++] = V[j++];
  for (int z = 0; z < n; ++z) V[e+z] = B[z];
  return res;
}


int main() {
  int n;
  while (cin >> n) {
    V = VI(n);
    for (int& x : V) cin >> x;
    cout << mergesort(0, n - 1) << endl;
  }
}
