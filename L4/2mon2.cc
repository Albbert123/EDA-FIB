#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> usat1;
//vector<bool> usat2;
vector<int> monedes;
vector<int> resultat;
int x,n;

void escriu(vector<int>& resultat) {
    cout << x << " = ";
    bool first = true;
    for(int i=0; i<resultat.size(); ++i) {
        if(resultat[i] != 0) {
            if(first) {
                first = false;
                cout << resultat[i];
            }
            else {
                cout << " + " << resultat[i];
            }
        }
    }
    cout << endl;
}

void canvi(int idx, int suma) {
    if(x == suma) escriu(resultat);

    else if(idx < resultat.size()) {
        if(suma < x) {
            int aux = resultat[idx]; //para deshacer backtrack despues
            resultat[idx] = monedes[idx/2]; //hay 2 monedas
            suma += monedes[idx/2];
            canvi(idx+1,suma);
            suma -= monedes[idx/2];
            resultat[idx] = aux;
            canvi(idx+1,suma);
        }
    }
}

int main() {
    while(cin >> x >> n) {
        usat1 = vector<bool>(n,false);
        //usat2 = vector<bool>(n,false);
        monedes = vector<int>(n);
        resultat = vector<int>(2*n);

        for(int i=0; i<n; ++i) cin >> monedes[i];
        sort(monedes.begin(), monedes.end());

        canvi(0,0);

        cout << "----------" << endl;
    }

}

/*
typedef vector<int> VI;
int bt (int k , const VI& m, int x, int sum par, int max und) {
if (sum par > x or sum par + max und < x) return 0;
if (k == m.size ()) return 1;
int cnt = 0;
for (int v = 0; v ≤ 2; ++v)
cnt += bt(k+1, m, x, sum par + v*m[k], max und − 2*m[k]);
return cnt ;
}
int main() {
int x, n;
while (cin >> x >> n) {
VI m(n);
int s = 0;
for (int k = 0; k < n; ++k) {
cin >> m[k];
s += m[k];
}
cout << bt(0, m, x, 0, 2*s) << endl;
}
}*/