#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//vector<bool> usat1;
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
                if(i%2 != 0) cout << "p";
            }
            else {
                cout << " + " << resultat[i];
                if(i%2 != 0) cout << "p";
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
            resultat[idx] = monedes[idx/2]; //hay 2 monedas: 1,1p,2,2p...
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
        //usat1 = vector<bool>(n,false);
        //usat2 = vector<bool>(n,false);
        monedes = vector<int>(n);
        resultat = vector<int>(2*n);

        for(int i=0; i<n; ++i) cin >> monedes[i];
        sort(monedes.begin(), monedes.end());

        canvi(0,0);

        cout << "----------" << endl;
    }

}