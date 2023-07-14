#include <iostream>
#include <vector>
using namespace std;


bool esta(double x, const vector<double>& v, int esq, int dre) {
  if (esq > dre) return false;
  int m = (esq + dre)/2;
  double y = v[m];
  if (m > 0 and v[m-1] > y) y = v[m-1];
  if (m < (int)v.size() - 1 and v[m+1] < y) y = v[m+1];
  if (x < y) return esta(x, v, esq, m - 1);
  if (x > y) return esta(x, v, m + 1, dre);
  return true;
}


bool resistant_search(double x, const vector<double>& v) {
  return esta(x, v, 0, v.size() - 1);
}


int main() {
}
