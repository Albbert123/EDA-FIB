#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,u,v,m;
vector<vector<int>> graf;

void dfs(int u, vector<bool>& vist) {
    if(vist[u]) return;
    vist[u] = true;
    for(int v : graf[u]) dfs(v,vist);
}

int main() {
    while(cin >> n >> u >> v >> m) {
        graf = vector<vector<int>>(n);
        for(int i=0; i<m; ++i) {
            int x,y;
            cin >> x >> y;
            graf[x].push_back(y);
            graf[y].push_back(x);
        }

        vector<bool> vist1(n,false);
        dfs(u,vist1);
        if(not vist1[v]) cout << 0 << endl;
        else {
            vector<bool> vist2(n,false);
            dfs(v,vist2);
            int sum=0;
            for(int x=0; x<n; ++x) {
                if(vist2[x] and vist1[x]) cout << x << endl;

            }
        }
        
    }
}