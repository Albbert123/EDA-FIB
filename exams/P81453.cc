#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> previ;

void cami(int ini, int fi){
    vector<bool> vist(n);
    previ = vector<int>(n,-1);
    queue<int> q;
    vist[ini] = true;
    q.push(ini);
    while(not q.empty()) {
        int u = q.front();
        q.pop();
        if(u == fi) return;
        for(int v : g[u]) {
            if(not vist[v]) {
                vist[v] = true;
                previ[v] = u;
                q.push(v);
            }
        }
    }
}

void escriu_path(int ini, int fi) {
    vector<int> path;
    for(int at = fi; at!=-1; at=previ[at]) {
        path.push_back(at);
    }

    bool f = true;
    for(int i=path.size()-1; i>=0; --i) {
        if(f) f = false;
        else cout << " ";
        cout << path[i];
    }
    cout << endl;
}

int main() {
    while(cin >> n >> m) {
        g = vector<vector<int>>(n);
        for(int i=0; i<m; ++i) {
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
        }

        for(int x=0; x<n; ++x) {
            sort(g[x].begin(), g[x].end());
        }

        cami(0,n-1);
        escriu_path(0,n-1);
    }
}