#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;

typedef vector<vector<int>> Graf;

list<int> topological(Graf& G, int n) {
    //n = G.size()
    vector<int> ge(n,0); //grau d'entrada dels vertex
    for(int u=0; u<n; ++u) {
        for(int i=0; i<G[u].size(); ++i) ++ge[G[u][i]]; //saber el grau d'entrada dels vertex
    }

    priority_queue<int, vector<int>, greater<int>> q; //guardem els vertex de grau 0, de menor a major
    for (int i = 0; i < n; ++i) {
        if (ge[i] == 0) q.push(i);
    }

    list<int> L; //la llista on estara la ordenacio topologica
    while(not q.empty()) {
        int u = q.top();
        q.pop();
        L.push_back(u);
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            --ge[v];
            if (ge[v] == 0) q.push(v);
        }
    }
    return L;
}

int main() {
    int n,m;
    while(cin >> n >> m) {
        Graf G(n);
        int x,y;
        for(int i=0; i<m; ++i) {
            cin >> x >> y;
            G[x].push_back(y); //aresta de x a y
        }
        list<int> L = topological(G,n);
        list<int>::iterator it;
        bool first = true; //per els espais
        for(it=L.begin(); it!=L.end(); ++it){
            if(first) first = false;
            else cout << " ";
            cout << *it;
        }
        cout << endl;
    }
    
}

