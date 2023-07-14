#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2){
  if(p1.first > p2.first) return true;
  else if(p1.first < p2.first) return false;
  else{
    //p1.first == p2.first
    if(p1.second >= p2.second) return false;
    else return true;
  }
}

int main() {
    map<string, pair<bool,int>> m; //nom, conectat/no, elo
    map<string, pair<bool,int>>::iterator it;
    string op;
    while(cin >> op) {
        if(op == "LOGIN") {
            string nom;
            cin >> nom;
            it = m.find(nom);
            if(it != m.end()) { //ya se habia conectado
                pair<bool,int> p = it->second;
                if(p.first == 0) { //no esta connectat
                    int elo = p.second; //recupera su elo de la sesion anterior
                    p = make_pair(1,elo); //ara esta connectada
                    m[nom] = p; 
                }
            }
            else { //nunca se habia conectado
                m[nom] = make_pair(1,1200);
            }
        }
        else if(op == "LOGOUT") {
            string nom;
            cin >> nom;
            it = m.find(nom);
            if(it != m.end()) { //ya se habia conectado
                pair<bool,int> p = it->second;
                if(p.first == 1) { //esta cionectado
                    int elo = p.second; //guardamos su elo
                    p = make_pair(0,elo); //se desconnecta
                    m[nom] = p;
                }
            }
        }
        else if(op == "PLAY") {
            map<string, pair<bool,int>>::iterator it2;
            string nom1, nom2;
            cin >> nom1 >> nom2;
            it = m.find(nom1);
            it2 = m.find(nom2);
            if(it != m.end() and it2 != m.end()) { //los 2 existen
                pair<bool,int> p1 = it->second;
				pair<bool,int> p2 = it2->second;
                if(p1.first == 1 and p2.first == 1) { //els 2 conectats
                    int elo = p1.second;
                    p1 = make_pair(1,elo+10);
                    m[nom1] = p1;
                    elo = p2.second;
                    if(elo >= 1210) {
                        p2 = make_pair(1,elo-10);
                        m[nom2] = p2;
                    }
                }
                else cout << "jugador(s) no connectat(s)" << endl;
            }
            else cout << "jugador(s) no connectat(s)" << endl;
        }
        else if(op == "GET_ELO") {
            string nom;
            cin >> nom;
            it = m.find(nom);
            if(it != m.end()) {
                pair<bool,int> p = it->second;
                cout << nom << " " << p.second << endl;
            }
        }
    }
    //ranking
    cout << endl;
    cout << "RANKING" << endl;
    vector<pair<int,string>> v(m.size());
	it = m.begin();
	int i = 0;
    //copia a vector
	while (it != m.end()) {
		v[i].first = it->second.second;
		v[i].second = it->first;
		++i;
		++it;
	}
    sort(v.begin(), v.end(), cmp);

    for (int i=0; i < v.size(); ++i) {
		cout << v[i].second << " " << v[i].first << endl;
	}
}