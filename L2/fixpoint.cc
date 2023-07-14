#include<iostream>
#include<vector>
using namespace std;

int fixed_point(vector<int>& v, int a, int esq, int dre) {
    if(esq>dre) return -1;
    int mid = (dre +esq)/2;
    //v[mid] + a = pos -> v[mid] = pos - a (vector; pos + 1)
    if(v[mid] < mid + 1 - a) return fixed_point(v,a,mid+1,dre);
    if(v[mid] > mid + 1 - a) return fixed_point(v,a,esq,mid-1);
    if(mid > 0 and v[mid-1] == mid - a) return fixed_point(v,a,esq,mid-1);
    else return mid + 1;

}

int main() {
    int cont_s = 0;
    int n;
    while (cin >> n) {
	    ++cont_s;
	    vector<int> v(n);
	    for (int j = 0; j < n; ++j) cin >> v[j];
	    int m,a;
	    cin >> m;
	    cout << "Sequence #" << cont_s << endl;
	    for (int i = 0; i < m; ++i) {
	        cin >> a;
	        int ret = fixed_point(v,a,0,n-1);
	        if (ret == -1) cout << "no fixed point for " << a << endl;
	        else cout << "fixed point for " << a << ": " << ret << endl;
	    }
	cout << endl;
    }
}