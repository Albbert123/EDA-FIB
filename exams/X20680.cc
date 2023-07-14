#include<iostream>
#include<vector>
using namespace std;

int n, c;
vector<char> res;
vector<bool> usat;

vector<char> v {'x','y','z'};

void escriu() {
    for(int i=0; i<n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

bool repetido(int idx, int i) {
    return idx>0 and res[idx-1] == v[i];
}

void par(int idx, int consec) {
    if(idx == n) escriu();

    else {
        for(int i=0; i<3; ++i) {
            int n_consec;
            if(repetido(idx,i)) n_consec = consec + 1;
            else n_consec = 1; //su no estas repe, minim 1 cop estas
            if(n_consec <= c) {
                res[idx] = v[i];
                par(idx+1,n_consec);
            }
        }
    }
}

int main() {
    while(cin >> n >> c) {
        res = vector<char>(n);
        usat = vector<bool>(n,0);

        par(0,0);

        cout << "--------------------" << endl;
    }
}