#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> g;
vector<int> graus_e;
int n,m;

bool ciclic(int n2) { //si es visiten els n vertex 1 cop(el primer s'ha de visitar 2 cops perq sigui ciclic) --> no es ciclic
    queue<int> q;
    for(int i=0; i<n; ++i) {
        if(graus_e[i] == 0) q.push(i);
    }

    while(not q.empty()) {
        int u = q.front();
        q.pop();
        --n2;
        for(int v : g[u]) {
            --graus_e[v];
            if(graus_e[v] == 0) q.push(v);
        }
    }
    return n2 > 0;
}

int main() {
    while(cin >> n >> m) {
        g = vector<vector<int>>(n);
        graus_e = vector<int>(n,0);
        for(int i=0; i<m; ++i) {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            ++graus_e[v];
        }
        if(ciclic(n)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}