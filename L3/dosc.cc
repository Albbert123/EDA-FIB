#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> G;
vector<bool> vist;

int n,m;

void dfs(int x) {
    if(vist[x]) return;
    vist[x] = true;
    
}

void color() {

}


int main() {
    while(cin >> n >> m) {
        G = vector<vector<int>>(n,vector<int>(m));
        for(int i=0; i<m; i++) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        color();
    }
}