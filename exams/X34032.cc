#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<char>> mat;
typedef pair<int,int> pos;
int n,m;

int X[8] = {1,2,2,1,-1,-2,-2,-1};
int Y[8] = {-2,-1,1,2,2,1,-1,-2};

bool pos_ok(int x,int y) {
    return x>=0 and x<n and y>=0 and y<m and mat[x][y]!='X';
}

int bfs(pos& ini) {
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pos> q;
    dist[ini.first][ini.second] = 0;
    q.push(ini);
    while(not q.empty()) {
        pos p = q.front();
        q.pop();
        if(mat[p.first][p.second] == 'p') return dist[p.first][p.second];
        for(int i=0; i<8; ++i) {
            int x = p.first + X[i];
            int y = p.second + Y[i];
            if(pos_ok(x,y) and dist[x][y] == -1) {
                dist[x][y] = dist[p.first][p.second] + 1;
                q.push(pos(x,y));
            }
        }
    }
    return -1;
}

int main() {
    while(cin >> n >> m) {
        mat = vector<vector<char>>(n,vector<char>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin >> mat[i][j];
            }
        }
        int f,c;
        cin >> f >> c;
        pos ini = pos(f-1,c-1);

        int d = bfs(ini);
        if(d == -1) cout << "no" << endl;
        else cout << d << endl;
    }
}