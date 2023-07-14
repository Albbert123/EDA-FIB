#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n,m;
vector<bool> usat;
vector<string> id;
vector<string> in;

void escriu(string& resultat) {
    cout << resultat << endl;
}

bool compatible(string a, char b) {
    string i1 = a+b;
    string i2 = b+a;
    bool test = true;
    for(int i=0; i<m; ++i) {
        if(in[i]==i1 or in[i]==i2) test = false;
    }
    return test;
}

void inc(int idx, string resultat) {
    if(idx == n) escriu(resultat);

    else {
        string x;
        if(idx==0) {
            for(int i=0; i<n; ++i) {
                if(not usat[i]) {
                    usat[i] = true;
                    x = resultat + id[i]; //PORQUE NO VA RES = RES + ID[I]?
                    inc(idx+1,x);
                    usat[i] = false;
                }
            }
        }
        else {
            for(int i=0; i<n; ++i) {
                if(not usat[i] and compatible(id[i],resultat[idx-1])) {
                    usat[i] = true;
                    x = resultat + id[i];
                    inc(idx+1,x);
                    usat[i] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    usat = vector<bool>(n,false);
    id = vector<string>(n);
    string s;

    for(int i=0; i<n; ++i) {
        cin >> s;
        id[i] = s;
    }

    cin >> m;
    in = vector<string>(m);

    for(int i=0; i<m; ++i) {
        cin >> s;
        in[i] = s;
    }

    inc(0,"");
}