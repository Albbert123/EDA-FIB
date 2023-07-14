#include<iostream>
#include<vector>
using namespace std;

int n;
vector<char> res;

bool comp(int a, int b) {
    return abs(a-b) <=2;
}

void escriu() {
    for(int i=0; i<n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

void perm(int idx, int na, int nb) {
    if(idx == n) escriu();

    else {
        if(comp(na+1,nb)) {
            res[idx] = 'a';
            perm(idx+1,na+1,nb);
        }

        if(comp(na,nb+1)) {
            res[idx] = 'b';
            perm(idx+1,na,nb+1);
        }
    }
}

int main() {
    cin >> n;
    res = vector<char>(n);

    perm(0,0,0);
}