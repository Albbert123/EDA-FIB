#include<iostream>
#include<vector>
using namespace std;

vector<bool> cons_usat;
vector<bool> voc_usat;
vector<char> cons;
vector<char> voc; 
vector<char> resultat;
int n;

void escriu(vector<char>& resultat){
    for(int i=0; i<2*n; ++i) cout << resultat[i];
    cout << endl;
}

void perm(int idx) {
    if(idx == 2*n) escriu(resultat);
    
    else {
        if(idx%2 == 0) {
            for(int j=0; j<n; ++j) {
                if(not cons_usat[j]) {
                    resultat[idx] = cons[j];
                    cons_usat[j] = true;
                    perm(idx+1);
                    cons_usat[j] = false;
                }
            }
        }
        else {
            for(int k=0; k<n; ++k) {
                if(not voc_usat[k]) {
                    resultat[idx] = voc[k];
                    voc_usat[k] = true;
                    perm(idx+1);
                    voc_usat[k] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    cons_usat = vector<bool>(n,false);
    voc_usat = vector<bool>(n,false);
    cons = vector<char>(n);
    voc = vector<char>(n);
    resultat = vector<char>(2*n);
    
    for(int i=0; i<n; ++i) cin >> cons[i];
    for(int j=0; j<n; ++j) cin >> voc[j];

    perm(0);
}