#include<iostream>
#include<vector>
using namespace std;

int m,n;
vector<int> l;
vector<bool> usat;

void escriu(int salt) {
    cout << salt << endl;
}

void perm(int idx, int salt) {
    if(salt <= m/2 and salt >= -m/2) {
        if(idx == n) escriu(salt);
        else {
            perm(idx+1, salt+l[idx]);
            perm(idx+1, salt-l[idx]);
        }
    } 

}

int main() {
    cin >> m >> n;
    l = vector<int>(n);
    usat = vector<bool>(n,false);
    for(int i=0; i<n; ++i) cin >> l[i];

    int salt;
    perm(0,0);
}