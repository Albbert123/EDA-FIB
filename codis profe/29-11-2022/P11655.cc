// P11655


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


void f(int i, int suma, int queda) {
  if (suma > s) return;
  if (suma + queda < s) return;

  if (i == n) return escriu();

  triat[i] = false;
  f(i + 1, suma, queda - num[i]);
  triat[i] = true;
  f(i + 1, suma + num[i], queda - num[i]);
}


int main() {
  cin >> s >> n;
  num = VI(n);
  int tot = 0;
  for (int& x : num) {
    cin >> x;
    tot += x;
  }
  triat = VB(n);
  f(0, 0, tot);
}
