#include<iostream>
#include<vector>
using namespace std;

int n,m,fi,ci,ff,cf;
vector<vector<char>> mat;
vector<vector<bool>> vist;
typedef pair<int,int> Pos;
vector<Pos> path;
int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};

bool pos_ok(int f, int c) {
    if(f>=0 and f<n and c>=0 and c<m) return true;
    return false;
}

void escriu() {
    for(int i=0; i<path.size(); ++i) {
        cout << mat[path[i].first][path[i].second];
    }
    cout << endl;
}

void tort() {
    Pos p = path.back();
    if(p.first == ff and p.second == cf) escriu();

    else {
        for(int i=0; i<4; ++i) {
            int nf = p.first + X[i];
            int nc = p.second + Y[i];
            if(pos_ok(nf,nc) and not vist[nf][nc]) {
                vist[nf][nc] = true;
                path.push_back(Pos(nf,nc));
                tort();
                path.pop_back();
                vist[nf][nc] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    mat = vector<vector<char>>(n,vector<char>(m));
    vist = vector<vector<bool>>(n,vector<bool>(m,false));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> mat[i][j];
        }
    }
    cin >> fi >> ci >> ff >> cf;
    vist[fi][ci] = true;
    path = vector<Pos>(1,Pos(fi,ci));

    tort();
}