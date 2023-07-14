#include <iostream>
#include <vector>

using namespace std;

void escriu (const vector<int>& nombres, vector<bool>& escollit) {
  cout << "{";
  bool algun_escrit = false;
  for (uint i = 0; i < nombres.size(); ++i)
    if (escollit[i]) {
      if (algun_escrit) cout << ",";
      else 	algun_escrit = true;
      cout <<nombres[i];
    }
  cout << "}" << endl;
}

void escriu_solucions (const vector<int>& nombres, int s, vector<bool>& escollit, int idx, int suma_parcial, int suma_restants) {
  if (suma_parcial > s) return;
  if (suma_parcial + suma_restants < s) return;
  
  if (idx == int(escollit.size())) {
    if (suma_parcial == s) escriu(nombres,escollit);
  }
  else  {
    escollit[idx] = true;
    escriu_solucions(nombres,s,escollit,idx+1,suma_parcial + nombres[idx], suma_restants - nombres[idx]);
    
    escollit[idx] = false;
    escriu_solucions(nombres,s,escollit,idx+1,suma_parcial, suma_restants - nombres[idx]);
  }
}

void escriu_solucions (const vector<int>& nombres, int s){ 
  vector<bool> escollit(nombres.size());
  int idx = 0;
  int suma_parcial = 0;
  int suma_restants = 0;
  for (int x : nombres) suma_restants += x;
  escriu_solucions(nombres, s, escollit, idx, suma_parcial,suma_restants);
}

int main ( ){
  // Llegim entrada
  int s;
  cin >> s;
  int n;
  cin >> n;  
  vector<int> nombres(n);
  for (int i = 0; i < n; ++i) cin >> nombres[i];
  
  // Calculo
  escriu_solucions(nombres,s);
}
