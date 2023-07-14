#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<vector<char>> mat;
typedef pair<int,int> pos;

int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};

bool pos_ok(int x,int y) {
    return x>=0 and x<n and y>=0 and y<m and mat[x][y]!='#';
}

pos bfs() { //return dist i persones
    vector<vector<int>> dist(n,vector<int>(m,-1));
    vector<vector<int>> pers(n,vector<int>(m,-1));
    dist[0][0] = 0;
    if(mat[0][0] == 'P') pers[0][0] = 1;
    else pers[0][0] = 0;
    queue<pos> q;
    q.push(pos(0,0));
    while(not q.empty()) {
        pos p = q.front();
        q.pop();
        if(mat[p.first][p.second] == 'T') return pos(dist[p.first][p.second],pers[p.first][p.second]);
        for(int i=0; i<4; ++i) {
            int x = p.first + X[i];
            int y = p.second + Y[i];
            if(pos_ok(x,y)) {
                int np = pers[p.first][p.second] + int(mat[x][y]=='P');
                if(dist[x][y] == -1) {
                    q.push(pos(x,y));
                    dist[x][y] = dist[p.first][p.second] + 1;
                    pers[x][y] = np;
                }
                else if(dist[x][y] == (dist[p.first][p.second]+1) and pers[x][y] < np) {
                    pers[x][y] = np;
                }
            }
        }
    }
    return pos(-1,0);
}

int main() {
    while(cin >> n >> m) {
        mat = vector<vector<char>>(n,vector<char>(m));
        bool found = false;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin >> mat[i][j];
                if(mat[i][j] == 'T') found = true;
            }
        }

        if(not found) cout << "El telecos ha fugit." << endl;
        else {
            pos res = bfs();
            if(res.first == -1) cout << "El telecos esta amagat." << endl;
            else cout << res.first << " " << res.second << endl;
        }
    }
}