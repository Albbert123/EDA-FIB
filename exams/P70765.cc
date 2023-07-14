#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n,p;
vector<string> s;
vector<int> res;

void escriu() {
    for(int i=0; i<p; ++i) {
        bool f = true;
        cout << "subconjunt " << i+1 << ": {";
        for(int j=0; j<n; ++j) {
            if(res[j] == i) {
                if(f) f = false;
                else cout << ",";
                cout << s[j];
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
    s = vector<string>(n);
    res = vector<int>(n);
    for(int i=0; i<n; ++i) cin >> s[i];
    cin >> p;

    part(0);
}
