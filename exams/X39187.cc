#include<iostream>
#include<vector>
using namespace std;

int n,c;
vector<char> res;

void escriu() {
    for(int i=0; i<n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

void mon(int idx, int nb, int c) {
    if(idx == n) escriu();

    else {
        if(c > 0) {
            res[idx] = 'b';
            mon(idx+1,nb+1,c-1);
        }

        if(nb > 0) {
            res[idx] = 's';
            mon(idx+1,nb-1,c+1);
        }
    }
}

int main() {
    cin >> n >> c;
    res = vector<char>(n);

    mon(0,0,c);
}