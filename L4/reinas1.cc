#include<iostream>
#include<vector>
using namespace std;

int n; //tablero nxn, colocar n reinas
vector<int> t; //la reina de la fila i és a la columna t[i]

// mc[j] si ja hi ha reina a la columna j,
// md1[k] si ja hi ha reina a la diagonal i+j = k, md2[k] si ja hi ha reina a la diagonal i− j + (n − 1) = k.
vector<bool> mc, md1, md2;

int diag1(int i, int j) { 
    return i+j; 

}
int diag2(int i, int j) {
    return i-j + n-1; 
}

int reinas(int i) {
    if(i==n) {
        return 1;
    }

    else {
        int res=0;
        for(int j=0; j<n; ++j) {
            if(not mc[j] and not md1[diag1(i,j)] and not md2[diag2(i,j)]) { //si no hay reinas amenazantes
                t[i] = j; //reina en fila i, columna j (t[i])
                //actualizamos posiciones
                mc[j] = true;
                md1[diag1(i,j)] = true;
                md2[diag2(i,j)] = true;
                res = res + reinas(i+1);
                //restauramos bajo backtrack
                mc[j] = false;
                md1[diag1(i,j)] = false;
                md2[diag2(i,j)] = false;
            }
        }
        return res;
    }
}

int main() {
    cin >> n;
    t = vector<int>(n);
    mc = vector<bool>(n,false);
    md1 = md2 = vector<bool>(2*n-1,false);
    cout << reinas(0) << endl;
}