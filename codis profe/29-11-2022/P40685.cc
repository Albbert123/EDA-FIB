// P40685


#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int s, n;
VI num;
VB triat;


void escriu() {
  bool primer = true;
  cout << '{';
  for (int i = 0; i < n; ++i)
    if (triat[i]) {
      if (primer) primer = false;
      else cout << ',';
      cout << num[i];
    }
  cout << '}' << endl;
}


void f(int i, int suma) {
  if (i == n) {
    if (suma == s) escriu();
    return;
  }

  triat[i] = false;
  f(i + 1, suma);
  triat[i] = true;
  f(i + 1, suma + num[i]);
}


int main() {
  cin >> s >> n;
  num = VI(n);
  for (int& x : num) cin >> x;
  triat = VB(n);
  f(0, 0);
}
