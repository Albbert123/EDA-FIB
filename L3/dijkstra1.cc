#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define INF 999999

typedef pair<int, int> ArcP; // arc amb pes; first = pes , second = vertex
typedef vector< vector<ArcP> > GrafP; // graf amb pesos

void dijkstra(const GrafP& G, int s, vector<int>& d,vector<int>& p) {
    int n = G.size();
    d = vector<int>(n,INF); //distancies
    d[s] = 0;
    p = vector<int>(n,-1); //previ
    vector<bool> S(n,false);
    priority_queue<ArcP,vector<ArcP>,greater<ArcP>> Q; //de menor a major
    Q.push(ArcP(0,s));

    while(not Q.empty()) {
        int u = Q.top().second; //vertex u
        Q.pop();
        if(not S[u]) {
            S[u] = true;
            for(int i=0; i<int(G[u].size()); ++i) {
                int c = G[u][i].first; //pes
                int v = G[u][i].second; //vertex
                if(d[u] + c < d[v]) { //si és mes gran que la distancia a u + pes
                    d[v] = d[u] + c;
                    p[v] = u;
                    Q.push(ArcP(d[v],v));
                }
            }
        }
    }
}

int main() {
    int n,m;
    while(cin >> n >> m) {
        vector<int> d; //distance
		vector<int> p; //predecesor
		GrafP G(n);
		ArcP arc; //c(pes) , v(vertex)
		int u; // vertex inicial
        for(int i=0; i<m; ++i) {
            cin >> u >> arc.second >> arc.first;
            G[u].push_back(arc);
        }
        int x,y; //de x a y
        cin >> x >> y;
        dijkstra(G,x,d,p);
        if(p[y]!=-1) cout << d[y] << endl;
        else if(x==y) cout << 0 << endl;
        else cout << "no path from " << x << " to " << y << endl;
    }
}