#include <iostream>
#include <stack>
#include <vector>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;


int main() {
  int n, m;
  cin >> n >> m;
  VVI G(n);
  VI grau(n, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    ++grau[y];
  }

  stack<int> pila;
  for (int x = 0; x < n; ++x)
    if (grau[x] == 0) pila.push(x);

  while (not pila.empty()) {
    int x = pila.top(); pila.pop();
    cout << x << endl;
    for (int y : G[x])
      if (--grau[y] == 0) pila.push(y);
  }
}
