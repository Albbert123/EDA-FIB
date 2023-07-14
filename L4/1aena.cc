#include<iostream>
#include<vector>
using namespace std;

void escriure(vector<int>& v) {
    cout << "(";
    for(int i=0; i<v.size(); ++i) {
        cout << v[i];
        if(i!=v.size()-1) cout << ",";
    }
    cout << ")" << endl;
}

// n: volem permutacions del nombres {1,2,...,n}
// v: permutacio parcial (mida n)
// idx: primera casella no omplerta de v
//vector usat: usat[k] és cert sii el nombre k ja apareix a la permutació parcial
void perm(int n, int idx, vector<int>& v, vector<bool>& usat) {
    if(idx == n) escriure(v);
    else {
        for(int k=1; k<=n; ++k) {
            cout << "el valor de idx es: " << idx << endl; //xivato
            if(not usat[k]) {
                cout << " la k (no usada) es: " << k << endl; //xivato
                usat[k] = true;
                v[idx] = k;
                for(int i=0; i<v.size(); ++i) cout << "En el vector v hay: " << v[i] << endl; //xivato
                perm(n,idx+1,v,usat);
                usat[k] = false; //restaurem sota backtrack
            }
            else cout << " la k (usada) es: " << k << endl; //xivato
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<bool> usat(n+1,false);
    perm(n,0,v,usat);
}