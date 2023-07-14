#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

struct Roca {
  double x;
  double y;
  double r;
};

typedef vector<Roca> Rocas;

bool can_jump(const Roca& a, const Roca& b, double d) {
  // √[(x_2 - x_1)^2 + (y_2 - y_1)^2] - r_1 - r_2
  return sqrt((b.x-a.x) * (b.x-a.x) + (b.y-a.y) * (b.y-a.y)) - a.r - b.r <= d;
}

int BFS(const Rocas& rocas, int n, double d) {
  vector<int> dist(n, -1);
  dist[0] = 0;
  queue<int> q;
  q.push(0);

  while (not q.empty()) {
    int u = q.front();
    q.pop();

    for (int w = 0; w < n; w++) {
      if (dist[w] == -1 and can_jump(rocas[u], rocas[w], d)) {
        dist[w] = dist[u] + 1;
        q.push(w);
        if (w == rocas.size() - 1) return dist[w];
      }
    }
  }

  return -1;
}

int main() {
  int n;
  double d;
  while (cin >> n >> d) {
    Rocas rocas(n);

    for(int i=0; i<n; ++i) {
        cin >> rocas[i].x >> rocas[i].y >> rocas[i].r;
    }

    int res = BFS(rocas, n, d);
    if (res == -1) cout << "Xof!" << endl;
    else cout << res << endl;
  }
}