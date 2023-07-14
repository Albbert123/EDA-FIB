#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 999999

typedef pair<int,int> ArcP; //arc amb pes; first = pes, second = vertex
typedef vector<vector<ArcP>> Grafp; //Graf amb pesos

void dij(Grafp& G, vector<int>& d, vector<int>& p, vector<int>& stp, int s) {
    int n = G.size();
    d = vector<int>(n,INF); //distancies
    stp = vector<int>(n,INF);
    d[s] = 0;
    stp[s] = 0;
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
                if (d[v] == -1 or (d[v] > d[u] + c) or (d[v] == d[u] + c and stp[v] > stp[u] + 1)){ //si és mes gran que la distancia a u + pes
                    d[v] = d[u] + c;
                    p[v] = u;
                    stp[v] = stp[u] + 1;
                    Q.push(ArcP(d[v],v));
                }
            }
        }
    }
}

int main() {
    int n,m;
    while(cin >> n >> m) {
        vector<int> d;
        vector<int> stp;
        vector<int> p;
        Grafp G(n);
        ArcP arc; //pes, vertex
        int u; //v inicial
        for(int i=0; i<m; ++i) {
            cin >> u >> arc.second >> arc.first;
            G[u].push_back(arc);
        }

        int x,y;
        cin >> x >> y;
        dij(G,d,p,stp,x);
        if(x==y) cout << "0" << endl;
        else if(d[y]!=-1) cout << "cost " << d[y] << ", " << stp[y] << " step(s)" << endl;
        else cout << "no path from " << x << " to " << y << endl;


    }

}