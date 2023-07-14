#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<int> cost_nit;
typedef pair<int,int> arc; //pes,vertex_d
vector<vector<arc>> g;

const int INF = 1e8;

int cost(int a, int b) {
    vector<int> dist(n,INF);
    priority_queue<arc,vector<arc>,greater<arc>> q;
    vector<bool> vis(n, false);
    dist[a] = 0;
    q.push(arc(0,a));
    while(not q.empty()) {
        arc p = q.top();
        q.pop();
        int du = p.first;
        int u = p.second;
        if(u == b) return dist[b];
        if(not vis[u]) {
            vis[u] = true;
            for(arc t : g[u]) {
                int w = t.first;
                int v = t.second;
                //int dv = dist [u] + w + (v == b ? 0 : cost_nit[v]);
                int dv = dist [u] + w;
                if(v != b) dv += cost_nit[v];
                if(dist[v] > dv) {
                    dist[v] = dv;
                    q.push(arc(dv,v));
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    cost_nit = vector<int>(n);
    for(int& x : cost_nit) cin >> x;
    g = vector<vector<arc>>(n);
    for(int i=0; i<m; ++i) {
        int u,v,c;
        cin >> u >> v >> c;
        g[u].push_back(arc(c,v));
        g[v].push_back(arc(c,u));
    }
    int a,b;
    while(cin >> a >> b) {
        int cost_total = cost(a,b);
        cout << "c(" << a << "," << b << ") = "; 
        if(cost_total != -1) cout << cost_total << endl;
        else cout << "+oo" << endl;
    }
}