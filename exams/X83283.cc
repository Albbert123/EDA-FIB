#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<vector<int>> graf;

int lluny() {
    queue<int> q;
    vector<int> dist(n,-1);
    q.push(0);
    dist[0] = 0;
    while(not q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graf[u]) {
            if (dist [v] == -1) {
                dist [v] = dist [u] + 1;
                q.push(v);
            }
        }
    }

    //calcular max
    int result = 0;
    for(int i=1; i<n; ++i) {
        if(dist[i] != -1 and dist[i] > dist[result]) result = i;
    }

    return result;
}

int main() {
    while(cin >> n >> m) {
        graf = vector<vector<int>>(n);
        for(int i=0; i<m; ++i) {
            int x,y;
            cin >> x >> y;
            graf[x].push_back(y);
            graf[y].push_back(x);
        }

        cout << lluny() << endl;
    }
}