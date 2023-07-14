#include<iostream>
#include<queue>
using namespace std;

int main() {
    char c;
    priority_queue<int> q;
    while(cin >> c) {
        int x;
        if(c == 'S') {
            cin >> x;
            q.push(x);
        }
        else if(c == 'A') {
           if(not q.empty()) cout << q.top() << endl;
           else cout << "error!" << endl;
        }
        else if(c == 'R') {
            if(not q.empty()) q.pop();
            else cout << "error!" << endl;
        }
        else if(c == 'I') {
            cin >> x;
            if (q.empty()) cout << "error!" << endl;
            else {
                int aux = q.top();
                q.pop();
                aux += x;
                q.push(aux);
            }
        }
        else if(c == 'D') {
            cin >> x;
            if(q.empty()) cout << "error!" << endl;
            else {
                int aux = q.top();
                q.pop();
                aux -= x;
                q.push(aux);
            }
        }

    }
}