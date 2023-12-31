// zeros i uns (1)


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


int n;
VI V;


void print() {
  for (int i = 0; i < n; ++i) cout << (i ? " " : "") << V[i];
  cout << endl;
}


void f(int i) {
  if (i == n) return print();

  V[i] = 0;
  f(i + 1);
  V[i] = 1;
  f(i + 1);
}


int main() {
  cin >> n;
  V = VI(n);
  f(0);
}
