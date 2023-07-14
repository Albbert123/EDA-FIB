#include <iostream>
#include <vector>
using namespace std;


int posicio(double x, const vector<double>& v, int esq, int dre) {
  if (esq > dre) return -1;
  int m = (esq + dre)/2;
  if (x < v[m]) return posicio(x, v, esq, m - 1);
  if (x > v[m]) return posicio(x, v, m + 1, dre);
  if (m == 0 or v[m-1] < x) return m;
  return posicio(x, v, esq, m - 1);
}


int first_occurrence(double x, const vector<double>& v) {
  return posicio(x, v, 0, v.size() - 1);
}


int main() {
}
