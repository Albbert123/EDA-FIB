#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef pair<string,string> p; //pers,propo

int main() {
    int n;
    while(cin >> n) {
        // Read proposals and create map: author to proposal
        map<string,string> prop; //autor,propo
        for(int i=0; i<n; ++i) {
            string person, proposal;
            cin >> person >> proposal;
            prop[proposal] = person;
        }

        // Read all vots and create map: (person,proposal) to bool
        int m;
        cin >> m;
        map<p,bool> vots;
        for(int i=0; i<m; ++i) {
            string name,vote,proposal;
            cin >> name >> vote >> proposal;
            vots[p(name,proposal)] = vote == "SI";
        }

        // Count votes for every proposal and store in map: proposal to (votes SI, votes NO)
        map<string,pair<int,int>> vots_propo;
        for(auto& elem : vots) {
            if(elem.second) ++vots_propo[elem.first.second].first;
            else ++vots_propo[elem.first.second].second;
        }

        // Write result
        for (auto& p : vots_propo) {
            if (p.second.first > p.second.second) {
                cout << p.first << ", de " << prop[p.first ] << ", que ha guanyat "
                << p.second.first << "-" << p.second.second << endl;
            }
        }
        cout << string(10, '-' ) << endl;
    }
}