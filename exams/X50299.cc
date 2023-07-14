#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n,m;
typedef pair<int,int> arc; //pes,vertex
vector<vector<arc>> g;

const int INF=1e8;

int dij(int s, int e) {
    vector<int> dist(n,INF);
    priority_queue<arc, vector<arc>, greater<arc>> q;
    dist[s] = 0;
    q.push(arc(0,s));
    while(not q.empty()) {
        arc t = q.top();
        q.pop();
        int d = t.first;
        int u = t.second;
        if(u == e) return dist[e];
        if(d == dist[u]) { //vist
            for(arc p : g[u]) {
                int l = p.first;
                int v = p.second;
                int d2 = max(dist[u],l);
                if(d2 < dist[v]) {
                    dist[v] = d2;
                    q.push(arc(d2,v));
                }
            }
        }
    }
    return INF;
}

int main() {
    while(cin >> n >>m) {
        g = vector<vector<arc>>(n);
        for(int i=0; i<m; ++i) {
            int x,y,l;
            cin >> x >> y >> l;
            g[x].push_back(arc(l,y));
        }

        cout << dij(0,1) << endl;
    }
}