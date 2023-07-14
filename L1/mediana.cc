#include<iostream>
#include<set>
using namespace std;

int main() {
    set<string> S;
    set<string>::iterator mediana = S.end();
    set<string>::iterator it;
    string s;
    cin >> s;
    while(s != "END") {
        S.insert(s);
        it = S.find(s);
        if(mediana == S.end()) mediana = it;
        else if(S.size()%2==0 and s<*mediana) --mediana;
        else if(S.size()%2!=0 and s>*mediana) ++mediana;
        cout << *mediana << endl;
        cin >> s;
    }

}