// zeros i uns (2)


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int n, u;
VI V;


void print() {
  for (int i = 0; i < n; ++i) cout << (i ? " " : "") << V[i];
  cout << endl;
}


void f(int i, int zeros, int uns) {
  if (zeros > n - u or uns > u) return;

  if (i == n) return print();

  V[i] = 0;
  f(i + 1, zeros + 1, uns);
  V[i] = 1;
  f(i + 1, zeros, uns + 1);
}


int main() {
  cin >> n >> u;
  V = VI(n);
  f(0, 0, 0);
}
