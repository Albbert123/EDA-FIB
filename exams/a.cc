#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n,m;
typedef pair<int,int> arc; //pes,vertex
vector<vector<arc>> g;
vector<int> previ;
vector<int> dist;

const int INF = 1e8;

int dij(int ini, int fi) {
    dist = vector<int>(n,INF);
    vector<int> vist(n,false);
    previ = vector<int>(n,-1);
    priority_queue<arc,vector<arc>,greater<arc>> q;
    dist[ini] = 0;
    q.push(arc(0,ini));
    while(not q.empty()) {
        arc p = q.top();
        q.pop();
        int du = p.first;
        int u = p.second;
        if(not vist[u]) {
            vist[u] = true;
            //if(u == fi) return dist[u];
            for(arc t : g[u]) {
                int dv = t.first;
                int v = t.second;
                if(dist[u] + dv < dist[v]) {
                    dist[v] = dist[u] + dv;
                    previ[v] = u;
                    q.push(arc(dv,v));
                }
            }
        }
    }
    return -1;
}

int main() {
    while(cin >> n >> m) {
        g = vector<vector<arc>>(n);
        for(int i=0; i<m; ++i) {
            int u,v,c;
            cin >> u >> v >> c;
            g[u].push_back(arc(c,v));
        }
        int x,y;
        cin >> x >> y;

        int cost = dij(x,y);
        if(previ[y] == -1) cout << "no path from " << x << " to " << y << endl;
        else if(x == y) cout << 0 << endl;
        else cout << dist[y] << endl;
    }
}