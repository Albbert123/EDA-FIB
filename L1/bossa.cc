#include<iostream>
#include<map>
using namespace std;

int main() {
    map<string,int> bossa;
    map<string,int>::iterator it;
    string op, paraula;

    while(cin >> op) {
        if (op == "minimum?") {
            if (bossa.empty()) cout << "indefinite minimum" << endl;
            else {
                it = bossa.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }

        }
        else if (op == "maximum?") {
            if (bossa.empty()) cout << "indefinite maximum" << endl;
            else {
                it = bossa.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
                
            }
        }
        else if (op == "store") {
            cin >> paraula;
            it = bossa.find(paraula);
            if(it == bossa.end()) bossa.insert(make_pair(paraula,1));
            else ++it->second;

        }
        else if (op == "delete") {
            cin >> paraula;
            it = bossa.find(paraula);
            if(it != bossa.end()) {
                --it->second;
                if(it->second == 0) bossa.erase(paraula);
            }
        }
    }

}