#include <iostream>
using namespace std;

int eleva(int n, int k, int m) {
    if(k==0) return 1;
    int x = eleva(n, k/2, m);
    x = (x*x)%m;
    if(k%2) x = (x*n)%m; //1001
    return x;
    }

int main() {
    int n, k, m;
    while(cin >> n >> k >> m) cout << eleva(n,k,m) << endl;
}