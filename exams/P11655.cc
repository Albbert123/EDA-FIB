#include<iostream>
#include<vector>
using namespace std;

int s,n;
vector<int> res;
vector<bool> vist;

void escriu() {
    cout << "{";
    bool f = true;
    for(int i=0; i<n; ++i) {
        if(vist[i]) {
            if(f) f= false;
            else cout << ",";
            cout << res[i];
        }
    }
    cout << "}" << endl;
}

void perm(int idx, int sum, int sum_resto) {
    if(idx == n) {
        if(s == sum) escriu();
    }

    else {
        if (sum + sum_resto - res[idx] >= s) {
            vist[idx] = false;
            perm(idx+1,sum, sum_resto-res[idx]);
        }
        if (sum + res[idx] <= s) {
            vist[idx] = true;
            perm(idx+1,sum + res[idx], sum_resto-res[idx]);
        }
    }
}

int main() {
    cin >> s >> n;
    res = vector<int>(n);
    vist = vector<bool>(n,false);
    int suma_resto = 0;
    for(int i=0; i<n; ++i) {
        cin >> res[i];
        suma_resto += res[i];
    }

    perm(0,0,suma_resto);
    
}
