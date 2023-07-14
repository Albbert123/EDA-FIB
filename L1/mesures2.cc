#include<iostream>
#include<queue>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    priority_queue<int> q;
    string op;
    int num;
    int max;
    double suma = 0;
    double cont = 0;
    while (cin >> op) {
        if (op == "number") {
            cin >> num;
            if (q.empty()) max = num;
            else if (max < num) max = num;
            q.push(-num);
            suma += num;
            ++cont;
        }
        else if (not q.empty() and op == "delete") {
            suma -= -q.top();
            q.pop();
            --cont;
        }

        if (not q.empty()) cout << "minimum: " << -q.top() << ", maximum: " << max << ", average: " << suma/cont << endl;
        else cout << "no elements" << endl;
    }
}