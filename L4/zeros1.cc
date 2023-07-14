#include<iostream>
#include<vector>
using namespace std;


void escriure(vector<int>& v) {
    for(int i=0; i<v.size(); ++i) {
        if(i!=0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

// idx: primera posicio no omplerta de v
// n: nombre de u+z que volem (i també mida de vector)
void zeros(vector<int>&v, int idx, int n) { 
    if(idx == n) escriure(v);
    else {
        v[idx] = 0;
        zeros(v,idx+1,n);
        v[idx] = 1;
        zeros(v,idx+1,n);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    zeros(v,0,n);
}