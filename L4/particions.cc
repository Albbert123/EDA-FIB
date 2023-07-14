#include<iostream>
#include<vector>
using namespace std;

int n,p;
vector<int> res;
vector<string> v;
vector<bool> usat;

void escriu() {
    for(int i=0; i<p; ++i) {
        cout << "subconjunt " << i+1 << ": {";
        bool first = true;
        for(int j=0; j<n; ++j) {
            if(res[j] == i) {
                if(first) first = false;
                else cout << ",";
                cout << v[j];
            } 
        }
        cout << "}" << endl;
    }
    cout << endl;
}

void part(int idx) {
    if(idx == n) escriu();

    else {
        for(int i=0; i<p; ++i) {
            res[idx] = i;
            part(idx+1);
        }
    }
}

int main() {
    cin >> n;
    v = vector<string>(n);
    usat = vector<bool>(n,false);
    for(int i=0; i<n; ++i) {
        cin >> v[i];
    }
    cin >> p;

    res = vector<int>(n);
    part(0);
}