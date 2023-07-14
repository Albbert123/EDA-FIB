#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<vector<int>> mat;
typedef pair<int,int> Cell;

const int INF = 1e8;

int X[4] = {1,0,-1,0};
int Y[4] = {0,1, 0, -1};

bool borde(Cell & c) {
    return c.first == 0 or c.second == 0 or c.first == n-1 or c.second == n-1;
}

int cost() { //dijkstra
    vector<vector<int>> dist(n,vector<int>(n,INF));
    vector<vector<bool>> vist(n,vector<bool>(n,false));
    Cell centro = {n/2, n/2};
    priority_queue<pair<int,Cell>, vector<pair<int,Cell>>, greater<pair<int,Cell>>> q; //<distancia,celda>

    dist[centro.first][centro.second] = mat[centro.first][centro.second];
    q.push({dist[centro.first][centro.second], centro});

    while(not q.empty()) {
        Cell c = q.top().second;
        q.pop();
        if(not vist[c.first][c.second]){
            vist[c.first][c.second] = true;
            if(borde(c)) return dist[c.first][c.second];
            for(int i=0; i<4; ++i) {
                int x = c.first + X[i];
                int y = c.second + Y[i];
                Cell lado = {x,y};
                if(dist[c.first][c.second] + mat[lado.first][lado.second] < dist[lado.first][lado.second]) {
                    dist[lado.first][lado.second] = dist[c.first][c.second] + mat[lado.first][lado.second];
                    q.push({dist[lado.first][lado.second], lado});
                }
            }
        }
    }
    return -1;
}

int main() {
    while(cin >> n) {
        mat = vector<vector<int>>(n,vector<int>(n));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) cin >> mat[i][j];
        }
        cout << cost() << endl;
    }
}