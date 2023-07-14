#include<iostream>
#include<map>
using namespace std;

int main() {
    int x, y, n;
    while(cin >> x >> y >> n) {
        map<int, int> collatz; // <n, repes>
        bool repetido = false;
        int posrepe = 0;
        collatz.insert(make_pair(n,0));
        map<int,int>::iterator it;
        while (n<=100000000 and not repetido) {
            ++posrepe;
            if(n%2==0) n = n/2 + x;
            else n = 3*n + y;
            it = collatz.find(n); //busquem si hi ha alguna n igual (repes)
            if (it == collatz.end()) collatz.insert(make_pair(n,posrepe)); //si no ha trobat res, seguim
            else repetido = true;
        }
        if(repetido) cout << collatz.size() - it->second << endl; //numero total de n - la posicion de la 1a repe
        else cout << n << endl;
    }
}