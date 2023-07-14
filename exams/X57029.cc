#include<iostream>
#include<vector>
using namespace std;

int n;
//vector<char> v = {'d','h','u'};
vector<char> res;

void escriu() {
    for(int i=0; i<n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

void mosca(int idx, int alçada) {
    if(idx == n) escriu();

    else {
        if(alçada > 0) {
            res[idx] = 'd';
            mosca(idx+1, alçada -1);
        }

        res[idx] = 'h';
        mosca(idx+1,alçada);

        res[idx] = 'u';
        mosca(idx+1,alçada+1);
    }
}

int main() {
    cin >> n;
    res = vector<char>(n);

    mosca(0,0);
}