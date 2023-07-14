#include<iostream>
#include<vector>
using namespace std;

int n;
vector<char> v{'A','C','G','T'};
vector<char> res;

void escriu() {
    for(int i=0; i<n; ++i) {
        cout << res[i];
    }
    cout << endl;
}

void adn(int idx) {
    if(idx == n) escriu();

    else {
        for(int i=0; i<4; ++i) {
            res[idx] = v[i];
            adn(idx+1);
        }
    }
}

int main() {
    cin >> n;
    res = vector<char>(n);

    adn(0);
}