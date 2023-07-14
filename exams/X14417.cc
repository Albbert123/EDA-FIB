#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<vector<string>> mat;
typedef pair<int,int> pos;

int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};

bool pos_ok(int x,int y) {
    return x>=0 and x<n and y>=0 and y<m and mat[x][y]!="*";
}

int bfs(pos&ini, pos&fi) {
    vector<vector<int>> dist(n,vector<int>(m,-1));
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
                dist[x][y] = dist[p.first][p.second] + 1;
                q.push(pos(x,y));
            }
        }
    }
    return -1;
}

pos posicio(string& s) {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(mat[i][j]==s) return pos(i,j);
        }
    }
    return pos(-1,-1);
}

int main() { 
    while(cin >> n >> m) {
        mat = vector<vector<string>>(n,vector<string>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) cin >> mat[i][j];
        }
        int p;
        cin >> p;
        vector<string> obj(p);
        for(int i=0; i<p; ++i) cin >> obj[i];

        vector<pos> pos_obj(p+1);
        pos_obj[0] = pos(0,0);
        for(int i=1; i<=p; ++i) {
            pos_obj[i] = posicio(obj[i-1]);
        }

        int path = 0;
        bool stop = false;
        int i=1;
        while(not stop and i<pos_obj.size()) {
            int dist = bfs(pos_obj[i-1],pos_obj[i]);
            if(dist == -1) stop = true;
            else {
                path += (dist + 1);
            }
            ++i;
        }

        if(stop) cout << "impossible" << endl;
        else cout << path << endl;
    }
}