#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

#define INF 999999

typedef pair<int,int> ArcP; // arc amb pes; first = pes , second = vertex
typedef vector<vector<ArcP> > GrafP; // graf amb pesos
vector<int> p;
vector<int> d;

void dijkstra(const GrafP& G, int s, int f) {
    int n = G.size();
    d = vector<int>(n,INF); //distancies
    d[s] = 0;
    p = vector<int>(n,-1); //previ
    vector<bool> S(n,false);
    priority_queue<ArcP,vector<ArcP>,greater<ArcP>> Q; //de menor a major
    Q.push(ArcP(0,s));

    while(not Q.empty() and Q.top().second != f) {
        int u = Q.top().second; //vertex u
        Q.pop();

        if(not S[u]) {
            S[u] = true;

            for(int i=0; i<int(G[u].size()); ++i) {
                int c = G[u][i].first; //pes
                int v = G[u][i].second; //vertex v
                if(d[u] + c < d[v]) { //si Ã©s mes gran que la distancia a u + pes
                    d[v] = d[u] + c;
                    p[v] = u;
                    Q.push(ArcP(d[v],v));
                }
            }
        }
    }
}

vector<int> funcio(const GrafP& G, int s, int f) {
    int n = G.size();
    vector<int> path;
    if(d[f]==INF) return path;
    for(int at = f; at!=-1; at = p[at]){
        path.push_back(at);
    }
    return path;

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
        dijkstra(G,x,y);
        vector<int> path = funcio(G,x,y);
        if(path.empty()) cout << "no path from " << x << " to " << y;

        bool first=true;
        for(int i=path.size()-1; i>=0; --i) {
            if(first) first = false;
            else cout << " ";
            cout << path[i];
        }
        cout << endl;
    }
}