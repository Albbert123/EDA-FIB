#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> arc; //pes,vertex_2
vector<vector<arc>> g;
int n,m;

const int INF = 1e8;

int ret(int cost_t) {
    priority_queue<arc,vector<arc>,greater<arc>> q;
    //vector<int> dist(n,INF);
    vector<bool> vist(n,false);
    vist[0] = true;
    for(arc p : g[0]) q.push(p);
    int v = 1; //vertex vist
    int sum = 0;
    while(v != n) {
        arc t = q.top();
        q.pop();
        int cost = t.first;
        int u = t.second;
        if(not vist[u]) {
            vist[u] = true;
            sum += cost;
            ++v;
            for(arc p : g[u]) q.push(p);
        }
    }
    return cost_t - sum;
}

int main() {
    while (cin >> n >> m) {
        g = vector<vector<arc>>(n);
        int cost_t = 0;
        for(int i=0; i<m; ++i) {
            int x,y,c;
            cin >> x >> y >> c;
            g[x].push_back(arc(c,y));
            g[y].push_back(arc(c,x));
            cost_t += c;
        }

        cout << ret(cost_t) << endl;
    }
}