#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e8;

int n,m;
vector<vector<int>> graf;
vector<bool> vist;

//retorna la size del componen connex
int size_comp(int u) {
    if(vist[u]) return 0;
    vist[u] = true;
    int res = 1;
    for(int v : graf[u]) {
        res += size_comp(v);
    }
    return res;
}

int main() {
    while(cin >> n >> m) {
        graf = vector<vector<int>>(n);
        vist = vector<bool>(n,false);
        for(int i=0; i<m; ++i) {
            int x,y;
            cin >> x >> y;
            graf[x].push_back(y);
            graf[y].push_back(x);
        }

        int mn=INF;
        int mx = 0;
        for(int x=0; x<n; ++x) {
            if(not vist[x]) {
                int s = size_comp(x);
                mn = min(mn,s);
                mx = max(mx,s);
            }
        }
        cout << mn << " " << mx << endl;

    }
}