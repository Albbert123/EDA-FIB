#include<iostream>
#include<vector>
using namespace std;

int x,n;
vector<int> mon;
vector<int> usat;

void perm(int idx, int sum, int& cont) {
    if(idx == n) {
        if(x == sum) ++cont;
    }

    else {

    }
}

int main() {
    while(cin >> x >> n) {
        mon = vector<int>(n);
        for(int i=0; i<n; ++i) cin >> mon[i];

        int cont=0;
        perm(0,0,cont);
    }
}