#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<int> graus_entrada;
vector<int> resultat;
typedef vector<vector<int>> Graf;

void llegir(Graf& par) {
    int x,y;
    for(int i=0; i<m; ++i) {
        cin >> x >> y;
        par[x].push_back(y);
        ++graus_entrada[y]; //aumentem graus_entrada vertex
    }
}

void escriu(vector<int>& resultat) {
    for(int i=0; i<resultat.size(); ++i) {
        if(i==0) cout << resultat[i];
        else cout << " " << resultat[i];
    }
    cout << endl;
}

void topo(int idx, Graf& par) {
    if(idx == n) escriu(resultat);

    else {
        for(int i=0; i<n; ++i) {
            if(graus_entrada[i] == 0) {
                resultat[idx] = i;
                --graus_entrada[i];
                for(int j=0; j<par[i].size(); ++j) { //treiem les arestes del vertex
                    --graus_entrada[par[i][j]];
                }
                topo(idx+1,par);
                ++graus_entrada[i];
                for(int j=0; j<par[i].size(); ++j) { //posem les arestes del vertex
                    ++graus_entrada[par[i][j]];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graus_entrada = vector<int>(n,0);
    resultat = vector<int>(n);
    Graf par(n);
    llegir(par);
    topo(0,par);
}