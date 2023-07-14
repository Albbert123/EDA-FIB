#include<iostream>
#include<vector>
using namespace std;

int f,c;
vector<int> t;  //torre en fila i, columna t[i];
vector<bool> mc; //mc[j] si hay torre en columna j

void escriu() {
    for(int i=0; i<f; ++i) {
        for(int j=0; j<c; ++j) {
            if(t[i] == j) cout << "R";
            else cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

void torre(int idx) {
    if(idx == f) escriu();

    else {
        for(int j=0; j<c; ++j) {
            if(not mc[j]) {
                t[idx] = j;
                mc[j] = true;
                torre(idx+1);
                mc[j] = false;
            }
        }
    }
}

int main() {
    cin >> f >> c;
    t = vector<int>(f);
    mc = vector<bool>(c,false);

    torre(0);
}