#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<vector<char>> mat;
vector<vector<bool>> vist_c;
vector<vector<bool>> vist_a;
typedef pair<int,int> Pos;

int Xa[4] = {1,-1,1,-1};
int Ya[4] = {1,1,-1,-1};

int Xc[8] = {1, 2, -1, -2, -2, -1, 1, 2};
int Yc[8] = {-2, -1, -2, -1, 1, 2, 2, 1};

bool pos_ok(int x, int y) {
    return x>=0 and x<n and y>=0 and y<m and mat[x][y] != 'T';
}

int dfs(Pos& p, int n_dir, int X[], int Y[], vector<vector<bool>>& vist) {

    /*
    int s = 0;
    vist[p.first][ p.second] = true;
    for (int i = 0; i < n_dir; ++i) {
        int x = p.first + X[i];
        int y = p.second + Y[i];
        Pos q(x,y);
        if (pos_ok(x,y) and not vist[x][y]) {
            s += dfs(q, n_dir, X, Y, vist);
        }
    }
    if ( mat[p.first][p.second] >= '0' and mat[p.first][p.second] <= '9' ) {
        s += mat[p.first][p.second] - '0';
        mat[p.first][p.second] = '.';
    }
    return s ;
    */

    int s = 0;
    queue<Pos> q;
    q.push(p);
    while(not q.empty()) {
        Pos p = q.front();
        q.pop();
        for(int i=0; i<n_dir; ++i) {
            int x = p.first + X[i];
            int y = p.second + Y[i];
            if(pos_ok(x,y) and not vist[x][y]) {
                vist[x][y] = true;
                q.push(Pos(x,y));
                if(mat[x][y] >= '0' and mat[x][y] <= '9') {
                    s += mat[x][y] - '0';
                    mat[x][y] = '.'; //recojemos moneda
                }
            }
        }
    }
    return s;
}

int main() {
    while(cin >> n >> m) {
        vector<Pos> cavall,alfil;
        mat = vector<vector<char>>(n,vector<char>(m));
        for(int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> mat[i][j];
                if(mat[i][j] == 'K') cavall.push_back(Pos(i,j));
                else if(mat[i][j] == 'B') alfil.push_back(Pos(i,j));
            }
        }

        int sum = 0;
        vist_c = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int k=0; k<cavall.size(); ++k) {
            Pos p = cavall[k];
            if(not vist_c[p.first][p.second]) {
                sum += dfs(p,8,Xc,Yc, vist_c);
            }
        }

        vist_a = vector<vector<bool>>(n,vector<bool>(m,false));
        for(int k=0; k<alfil.size(); ++k) {
            Pos p = alfil[k];
            if(not vist_a[p.first][p.second]) {
                sum += dfs(p,4,Xa,Ya,vist_a);
            }
        }

        cout << sum << endl;
    }
}