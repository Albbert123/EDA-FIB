// P82660


#include <iostream>
#include <vector>
#include <algorithm>
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


bool f(int i, int suma) {
  if (i == n) {
    if (suma != s) return false;
    escriu();
    return true;
  }

  triat[i] = true;
  if (f(i + 1, suma + num[i])) return true;
  triat[i] = false;
  return f(i + 1, suma);
}


bool comp(int a, int b) {
  return a > b;
}


int main() {
  cin >> s >> n;
  num = VI(n);
  for (int& x : num) cin >> x;
  sort(num.begin(), num.end(), comp);
  triat = VB(n);
  if (not f(0, 0)) cout << "no solution" << endl;
}
