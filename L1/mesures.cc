#include<iostream>
#include<queue>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    priority_queue<int, vector<int>, greater<int>> q; //top es el mes petit (de major a menor)
    string op;
    int num;
    int max;
    double suma = 0;
    while (cin >> op) {
        if (op == "number") {
            cin >> num;
            if (q.empty()) max = num;
            else if (max < num) max = num;
            q.push(num);
            suma += num;
        }
        else if (not q.empty() and op == "delete") {
            suma -= q.top();
            q.pop();
        }

        if (not q.empty()) cout << "minimum: " << q.top() << ", maximum: " << max << ", average: " << suma/q.size() << endl;
        else cout << "no elements" << endl;
    }
}