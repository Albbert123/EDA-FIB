#include<iostream>
#include<vector>
using namespace std;

int n,d;
//vector<int> res;
vector<bool> vist;

bool es_eq(int left, int act) {
    return abs(left-act) <= d;
}

void escriu(vector<int>& res) {
    cout << "(";
    for(int i=0; i<n; ++i) {
        if(i==n-1) cout << res[i];
        else cout << res[i] << ",";
    }
    cout << ")" << endl;
}

void seq(int idx, vector<int>& res) {
    if(idx == n) escriu(res);

    else {
        for(int k=1; k<=n; ++k) {
            if(not vist[k]) {
                if(res.size() < 1 or es_eq(res.back(),k)) {
                    res.push_back(k);
                    vist[k] = true;
                    seq(idx+1,res);
                    res.pop_back();
                    vist[k] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n >> d;
    vector<int> res;
    vist = vector<bool>(n,false);

    seq(0,res);

}