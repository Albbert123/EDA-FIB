#include<iostream>
#include<map>
using namespace std;

bool buy(map<string,int>& m, const string& game, int totalgames) {
    return m[game] + 1 <= totalgames - m[game];
}

int main() {
    int n;
    while(cin >> n) {
        map<string,int> m;
        int totalgames = 0;
        for(int i=0; i<n; ++i) {
            string game;
            cin >> game;
            ++m[game];
            ++totalgames;
        }

        int j;
        cin >> j;
        for(int i=0; i<j; ++i) {
            string game;
            cin >> game;
            if(buy(m,game,totalgames)) {
                ++m[game];
                ++totalgames;
            }
        }

        map<string,int>::iterator it;
        for(it = m.begin(); it != m.end(); ++it) cout << it->first << " " << it->second << endl;
        cout << "--------------------" << endl;

    }
}