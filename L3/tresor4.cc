#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef vector<vector<int>> Dist;

const int X[4] = {1,0,-1,0};
const int Y[4] = {0,1,0,-1};

int tresor(vector<vector<char>>& T, int n, int m, int f, int c){
    queue<pair<int,int>> q;
    Dist dist(n,vector<int>(m,-1));
    q.push(pair<int,int>(f,c));
    dist[f][c] = 0;
    int d = 0;
    while(not q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int x = p.first + X[i];
            int y = p.second + Y[i];
            if ((x < n and x >= 0) and (y < m and y >= 0) and (T[x][y] != 'X' and dist[x][y] == -1)) {
                if(T[x][y]=='t') {
                    if(d < dist[p.first][p.second] + 1) d = dist[p.first][p.second] + 1;
                }
                q.push(pair<int,int>(x,y));
                dist[x][y] = dist[p.first][p.second] + 1;
                //T[x][y] = 'X';
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> T(n,vector<char>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> T[i][j];
        }
    }
    int f, c;
    cin >> f >> c;
    int distmax = tresor(T,n,m,f-1,c-1);
    if (distmax == 0) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia maxima: " << distmax << endl;
}