#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int Xp[4] = {1,0,-1,0};
int Yp[4] = {0,1,0,-1};

int Xf[8] = {-1,-1,0,1,1,1,0,-1};
int Yf[8] = {0,-1,-1,-1,0,1,1,1};

int n,m;
vector<vector<char>> mat;
vector<vector<bool>> vist;
typedef pair<int,int> Pos;

bool pos_ok(int x, int y) {
    return x>=0 and x<n and y>=0 and y<m and mat[x][y]!='X';
}

bool dfs(Pos& p) {
    queue<Pos> q;
    if(mat[p.first][p.second] == 'X') return false; //per si hi ha hagut un fantasma al costat d'un pacman
    q.push(p);
    while(not q.empty()) {
        Pos p1 = q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int x = p1.first + Xp[i];
            int y = p1.second + Yp[i];
            if(pos_ok(x,y) and not vist[x][y]) {
                vist[x][y] = true;
                if(mat[x][y] == 'B') return true;
                q.push(Pos(x,y));
            }
        }
    }
    return false;
}

int main() {
    while(cin >> n >> m) {
        mat = vector<vector<char>>(n,vector<char>(m));
        vist = vector<vector<bool>>(n,vector<bool>(m,false));
        Pos p;
        queue<Pos> F;

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin >> mat[i][j];
                if(mat[i][j] == 'P') {
                    p.first = i;
                    p.second = j;
                }
                if(mat[i][j] == 'F') F.push(Pos(i,j));
            }
        }

        //rodejem els fantasmas de X perq pacman no passi
        while(not F.empty()) {
            Pos f = F.front();
            F.pop();
            for(int k=0; k<8; ++k) {
                int i = f.first + Xf[k];
                int j = f.second + Yf[k];
                mat[i][j] = 'X';
            }
        }

        if(dfs(p)) cout << "si" << endl;
        else cout << "no" << endl;
    } 
}




