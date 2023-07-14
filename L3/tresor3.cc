#include<iostream>
#include<vector>

using namespace std;

void tresor(vector<vector<char>>& T, vector<vector<bool>>& visitat, int n, int m, int f, int c, int& count) {
    if(not visitat[f][c]) {
        visitat[f][c] = true;
        if(T[f][c]=='t') ++count;
        if(T[f][c]!='X') {
            if(f != n-1) tresor(T,visitat,n,m,f+1,c,count);
            if(f != 0) tresor(T,visitat,n,m,f-1,c,count);
            if(c != m-1) tresor(T,visitat,n,m,f,c+1,count);
            if(c != 0) tresor(T,visitat,n,m,f,c-1,count);
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
    int count = 0;
    tresor(T,visitat,n,m,f-1,c-1,count);
    cout << count << endl;
}