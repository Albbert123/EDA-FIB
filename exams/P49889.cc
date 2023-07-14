#include<iostream>
#include<vector>
using namespace std;

int n;
vector<char> voc;
vector<char> con;
vector<char> res;
vector<bool> con_usat;
vector<bool> voc_usat;

void escriu() {
    for(int i=0; i<2*n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

void perm(int idx) {
    if(idx == 2*n) escriu();

    else {
        for(int i=0; i<n; ++i) {
            if(idx%2 == 0) {
                if(not con_usat[i]) {
                    con_usat[i] = true;
                    res[idx] = con[i];
                    perm(idx+1);
                    con_usat[i] = false;
                }
            }
            else {
                if(not voc_usat[i]) {
                    voc_usat[i] = true;
                    res[idx] = voc[i];
                    perm(idx+1);
                    voc_usat[i] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    voc = vector<char>(n);
    con = vector<char>(n);
    res = vector<char>(2*n);
    con_usat = vector<bool>(n,false);
    voc_usat = vector<bool>(n,false);
    for(int i=0; i<n; ++i) cin >> con[i];
    for(int i=0; i<n; ++i) cin >> voc[i];

    perm(0);
}