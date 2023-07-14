#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> t; //reina fila i es a a columna t[i]

vector<bool> mc,md1,md2;

int diag1(int i, int j) {
    return i+j;
}

int diag2(int i, int j) {
    return i-j + n-1;
}

void write() {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(t[i] == j) cout << "Q";
            else cout << ".";
        }
        cout << endl;
    }
}

void reinas(int i, bool& trobat) {
    if(i==n) {
        write();
        trobat = true;
    }

    else {
        int j=0;
        while(j<n and not trobat) {
            if(not mc[j] and not md1[diag1(i,j)] and not md2[diag2(i,j)]) {
                t[i] = j;
                mc[j] = true;
                md1[diag1(i,j)] = true;
                md2[diag2(i,j)] = true;
                reinas(i+1,trobat);
                mc[j] = false;
                md1[diag1(i,j)] = false;
                md2[diag2(i,j)] = false;
            }
            ++j;
        }
    }
}

int main(){
    cin >> n;
    t = vector<int>(n);
    mc = vector<bool>(n,false);
    md1 = md2 = vector<bool>(2*n-1,false);
    bool trobat = false;
    reinas(0,trobat);
    if(not trobat) cout << "NO SOLUTION" << endl;
}