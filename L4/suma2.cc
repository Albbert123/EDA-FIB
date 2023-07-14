#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int s,n;
vector<bool> vist;
vector<int> v;

bool cmp(int a, int b) {
    return a>b;
}

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

bool suma(int idx, int sum) {
    if(idx == n) {
        if (sum == s) {
            escriu();
            return true;
        }
        else return false;
    }

    else {
        vist[idx] = true;
        bool b = suma(idx+1,sum+v[idx]);
        if(not b) {
            vist[idx] = false; //si la combinacion no es posible
            return suma(idx+1,sum);
        }
        else return true;
    }
}

int main() {
    cin >> s;
    cin >> n;
    vist = vector<bool>(n,false);
    v = vector<int>(n);
    for(int i=0; i<n; ++i) cin >> v[i];
    sort(v.begin(), v.end(), cmp);

    if(not suma(0,0)) cout << "no solution" << endl;
}