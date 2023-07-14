#include<iostream>
#include<vector>
using namespace std;

int n;
vector<char> res;
vector<bool> usat;

//char alf[9] = {'a','b','c','d','e','f','g','h','i'};

bool prohibit(char left, char act) {
    return act == left;
}

void escriu() {
    for(int i=0; i<n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

void par(int idx) {
    if(idx == n) escriu();

    else {
        for(int k=0; k<n; ++k) {
            if(not usat[k]) {
                if(res.size() == 0 or not prohibit(res[idx-1]+1,'a' + k)) {
                    usat[k] = true;
                    res[idx] = 'a' + k;
                    par(idx+1);
                    usat[k] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    res = vector<char>(n,'a');
    usat = vector<bool>(n,false);

    par(0);
}

