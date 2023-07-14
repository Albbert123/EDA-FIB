#include<iostream>
#include<vector>
using namespace std;

void escriure(vector<string>& v, vector<int>& sol) {
    cout << "(";
    for(int i=0; i<v.size(); ++i) {
        cout << v[sol[i]];
        if(i!=v.size()-1) cout << ",";
    }
    cout << ")" << endl;
}

// n: volem permutacions del nombres {1,2,...,n}
// v: permutacio parcial (mida n)
// idx: primera casella no omplerta de v
// sol: solucions de las permutacions
// usat: usat[k] és cert sii el nombre k ja apareix a la permutació parcial
void perm(int n, int idx, vector<string>& v, vector<int>& sol, vector<bool>& usat) {
    if(idx == n) escriure(v,sol);
    else {
        for(int k=0; k<n; ++k) {
            if(not usat[k]) {
                usat[k] = true;
                sol[idx] = k;
                perm(n,idx+1,v,sol,usat);
                usat[k] = false; //restaurem sota backtrack
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    vector<int> sol(n);
    vector<bool> usat(n,false);
    perm(n,0,v,sol,usat);
}