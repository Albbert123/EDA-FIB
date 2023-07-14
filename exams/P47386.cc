#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
    map<string,string> liats;
    string opc;
    while(cin >> opc) {
        if(opc == "liats") {
            string x,y;
            cin >> x >> y;
            //si estavan con aliguen, ese alguien soltero
            if(liats[x]!="") liats[liats[x]] = "";
            if(liats[y]!="") liats[liats[y]] = "";
            liats[x] = y;
            liats[y] = x;
        }

        else if(opc == "info") {
            cout << "PARELLES:" << endl;
            map<string,string>::iterator it;
            for(it=liats.begin(); it!=liats.end(); ++it) {
                if(it->second!="" and it->first < it->second)
                cout << it->first << " " << it->second << endl;
            }
            cout << "SOLS:" << endl;
            for(it=liats.begin(); it!=liats.end(); ++it) {
                if(it->second=="")
                cout << it->first << endl;
            }
            cout << "----------" << endl;
        }
    }
}