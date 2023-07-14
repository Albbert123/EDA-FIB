#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> g;
vector<int> c;
int n,m;

// Returns true if no conflict is found.
bool propaga(int x, int col) {
    if(c[x] == -1) {
        c[x] = col;
        for(int y : g[x]) {
            if(not propaga(y,1-col)) return false;
        }
        return true;
    }
    else return c[x] == col;
}

bool color(int x) {
    if(x == n) return true;
    if(c[x] == -1) return propaga(x,0) and color(x+1);
    else return color(x+1);
}

int main() {
    while (cin >> n >> m) {
        g = vector<vector<int>>(n);
        c = vector<int>(n,-1);
        for(int i=0; i<m; ++i) {
            int x,y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        if(color(0)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}