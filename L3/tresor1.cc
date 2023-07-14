#include<iostream>
#include<vector>

using namespace std;

void tresor(vector<vector<char>>& T, vector<vector<bool>>& visitat, int f, int c, bool& trobat) {
    int n = T.size();
    int m = T[0].size();
    if(not visitat[f][c] and not trobat) {
        visitat[f][c] = true;
        if(T[f][c]=='t') trobat = true;
        else if(T[f][c]!='X') {
            if(f != n-1) tresor(T,visitat,f+1,c,trobat);
            if(f != 0) tresor(T,visitat,f-1,c,trobat);
            if(c != m-1) tresor(T,visitat,f,c+1,trobat);
            if(c != 0) tresor(T,visitat,f,c-1,trobat);
        }
    }
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
    vector<vector<bool>> visitat(n,vector<bool>(m,false));
    bool trobat = false;
    tresor(T,visitat,f-1,c-1,trobat);
    if(trobat) cout << "yes" << endl;
    else cout << "no" << endl;
}