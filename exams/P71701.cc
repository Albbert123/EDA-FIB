#include<iostream>
#include<vector>
using namespace std;

int n,r;
vector<vector<bool>> mat;

bool evita_amanaces(int i, int j) {
    if(mat[i][j]) return false;
    else if(i-1>=0 and mat[i-1][j]) return false;
    else if(i-1>=0 and j-1>=0 and mat[i-1][j-1]) return false;
    else if(j-1>=0 and mat[i][j-1]) return false;
    else if(i+1<n and j-1>=0 and mat[i+1][j-1])  return false;
    else if(i+1<n and mat[i+1][j])  return false;
    else if(i+1<n and j+1<n and mat[i+1][j+1])  return false;
    else if(j+1<n and mat[i][j+1])  return false;
    else if(i-1>=0 and j+1<n and mat[i-1][j+1])  return false;
    return true;
}

void escriu() {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(mat[i][j]) cout << "K";
            else cout << ".";
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

void next_i(int i, int j, int& ni, int& nj) {
    if ( j < n-1) {
        ni = i ;
        nj = j+1;
    }
    else {
        ni = i+1;
        nj = 0;
    }
}

void rei(int i, int j, int s) {
    if(r==s) escriu();

    else if(i!=n) {
        int ni,nj;
        next_i(i,j,ni,nj);
        if(evita_amanaces(i,j)) {
            mat[i][j] = true;
            rei(ni,nj,s+1);
        }
        mat[i][j] = false;
        rei(ni,nj,s);
    }
}

int main() {
    cin >> n >> r;
    mat = vector<vector<bool>>(n,vector<bool>(n,false));

    rei(0,0,0);
}