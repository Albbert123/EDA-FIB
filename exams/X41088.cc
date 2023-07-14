#include<iostream>
#include<vector>
using namespace std;

int n;
//vector<int> res;
vector<bool> usat;

bool te_pou(int l, int mid, int r) {
    return l+r > 2*mid;
}

void escriu(vector<int>& res) {
    cout << "(";
    for(int i=0; i<n; ++i) {
        if(i==n-1) cout << res[i];
        else cout << res[i] << ",";
    }
    cout << ")" << endl;
}

void pou(int idx, vector<int>& res) {
    if(idx == n) escriu(res);

    else {
        for(int k=1; k<=n; ++k) {
            if(not usat[k]) {
                if(res.size() < 2 or not te_pou(res[res.size()-2],res.back(),k)) { // l,mid,r
                    res.push_back(k);
                    //res[idx] = k;
                    usat[k] = true;
                    pou(idx+1,res);
                    usat[k] = false;
                    res.pop_back();
                }
            }
        }
    }
}

int main() {
    cin >> n;
    vector<int> res;
    usat = vector<bool>(n,false);

    pou(0,res);

}