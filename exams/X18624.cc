#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<char> res;
vector<char> v;

bool es_vocal(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

bool repito_vocal(int idx) {
    return idx>0 and es_vocal(res[idx-1]);
}

void escriu() {
    for(int i=0; i<n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

void runa(int idx) {
    if(idx == n) escriu();

    else {
        for(int i=0; i<m; ++i) {
            if(not es_vocal(v[i]) or not repito_vocal(idx)) {
                res[idx] = v[i];
                runa(idx+1);
            }
        }
    }
}

int main() {
    while(cin >> n >> m) {
        res = vector<char>(n);
        v = vector<char>(m);
        for(int i=0; i<m; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        runa(0);

        cout << "----------" << endl;
    }
}