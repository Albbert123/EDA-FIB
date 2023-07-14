#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pos;
vector<vector<char>> mat;
int n,m;

int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};

//int DI[8] = {1,1,0,-1,-1,-1,0,1};
//int DJ[8] = {0,1,1,1,0,-1,-1,-1};

bool pos_ok(int x, int y) {
    return x>=0 and x<n and y>=0 and y<m and mat[x][y]!='M';
}

int bfs(pos& ini, pos& fi) {
    vector<vector<int>>dist(n,vector<int>(m,-1));
    queue<pos> q;
    dist[ini.first][ini.second] = 0;
    q.push(ini);
    while(not q.empty()) {
        pos p = q.front();
        q.pop();
        if(p == fi) return dist[p.first][p.second];
        for(int i=0; i<4; ++i) {
            int x = p.first + X[i];
            int y = p.second + Y[i];
            if(pos_ok(x,y) and dist[x][y] == -1) {
                dist[x][y] = dist[p.first][p.second]+1;
                q.push(pos(x,y));
            }
        }
    }
    return -1;
}

int main() {
    while(cin >> n >> m) {
        mat = vector<vector<char>>(n, vector<char>(m));
        pos ini,fi;
        queue<pos> monster;
        for(int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> mat[i][j];
                if(mat[i][j] == 'I') ini = pos(i,j);
                if(mat[i][j] == 'F') fi = pos(i,j);
                if(mat[i][j] == 'M') monster.push(pos(i,j));
            }
        }

        //poner M alrededor de los monstruos
        while(not monster.empty()) {
            pos mo = monster.front();
            monster.pop();
            for(int i=0; i<4; ++i) {
            int x = mo.first + X[i];
            int y = mo.second + Y[i];
            if(x>=0 and x<n and y>=0 and y<m) mat[x][y] = 'M';
            }
        }

        int dist = bfs(ini,fi);
        if(dist!=-1) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
}