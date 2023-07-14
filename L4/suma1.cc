#include<iostream>
#include<vector>
using namespace std;

int s,n;
vector<bool> vist;
vector<int> v;

void escriu() {
    bool first = true;
    cout << "{";
    for(int i=0; i<n; ++i) {
        if(vist[i]) {
            if(first) first = false;
            else cout << ",";
            cout << v[i];
        }
    }
    cout << "}" << endl;
}

void suma(int idx, int sum) {
    if(idx == n) {
        if (sum == s) escriu();
    }

    else {
        vist[idx] = true;
        suma(idx+1,sum+v[idx]);
        vist[idx] = false; //si la combinacion no es posible
        suma(idx+1,sum);
    }
}

int main() {
    cin >> s;
    cin >> n;
    vist = vector<bool>(n,false);
    v = vector<int>(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    suma(0,0);
}