#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int X[8] = {1,2,2,1,-1,-2,-2,-1};
int Y[8] = {-2,-1,1,2,2,1,-1,-2};

typedef pair<int,int> pos;
int n,m,w,l,k;

bool pos_ok(int x, int y) {
    return x>=0 and x<n and y>=0 and y<m;
}

int bfs(const pos& ini, const pos& fi) {
    vector<vector<int>> dist(n,vector<int>(m,-1));
    dist[ini.first][ini.second] = 0;
    queue<pos> q;
    q.push(ini);
    while(not q.empty()) {
        pos p = q.front();
        q.pop();
        if(p == fi) return dist[p.first][p.second];
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
    while(cin >> n >> m >> w >> l >> k) {
        vector<pos> ob(k+1);
        ob[0] = pos(0,0);
        for(int i=1; i<=k; ++i) {
            int x,y;
            cin >> x >> y;
            ob[i] = pos(x,y);
        }

        int sum=0;
        int best_sum = 0;
        bool stop = false;
        int i=0;
        while(not stop and i<ob.size() -1) {
            int d = bfs(ob[i],ob[i+1]);
            if(d==-1) stop = true;
            else {
                sum += w;
                sum -= l*d;
                ++i;
                if(sum > best_sum) best_sum = sum;
            }
        }
        cout << best_sum << endl;
    }
}