#include<iostream>
#include<vector>
using namespace std;


void escriure(vector<int>& v) {
    for(int i=0; i<v.size(); ++i) {
        if(i!=0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

// idx: primera posicio no omplerta de v
// uns: nombre d’1s que hi ha en v[0...idx-1] (ja portem posats)
// zeros: nombre de 0s que hi ha en v[0...idx-1] (ja portem posats)
// u: nombre total d’1s que volem
void zerosuns(vector<int>&v, int idx, int n, int u, int zeros, int uns) { 

    if(idx == n) escriure(v);

    else {

        if(zeros < n - u) { //no tots els 0's posats
            v[idx] = 0;
            zerosuns(v,idx+1,n,u,zeros+1,uns);
        }

        if(uns < u) { // no tots els 1's posats
            v[idx] = 1;
            zerosuns(v,idx+1,n,u,zeros,uns+1);
        }
    }   

/*    
    //una altre manera de fer-ho
    if((zeros <= n - u) and (uns <= u)) {
    
        if(idx == n) escriure(v);

        else {
            v[idx] = 0;
            zerosuns(v,idx+1,n,u,zeros+1,uns);
            v[idx] = 1;
            zerosuns(v,idx+1,n,u,zeros,uns+1);
        }
    }
*/
}

int main() {
    int n, u;
    cin >> n >> u;
    vector<int> v(n);
    zerosuns(v,0,n,u,0,0);
}