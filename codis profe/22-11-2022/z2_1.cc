// zeros i uns (2) (lent)


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


void f(int i) {
  if (i == n) {
    int q = 0;
    for (int x : V) q += x;
    if (q != u) return;
    return print();
  }

  V[i] = 0;
  f(i + 1);
  V[i] = 1;
  f(i + 1);
}


int main() {
  cin >> n >> u;
  V = VI(n);
  f(0);
}
