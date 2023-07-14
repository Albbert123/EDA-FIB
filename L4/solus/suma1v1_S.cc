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

void escriu_solucions (const vector<int>& nombres, int s, vector<bool>& escollit, int suma_parcial) {

  if (escollit.size() == nombres.size()) {
    if (suma_parcial == s) escriu(nombres,escollit);
  }
  else  {
    escollit.push_back(true);
    escriu_solucions(nombres,s,escollit,suma_parcial + nombres[escollit.size() - 1]);
    
    escollit.back() = false;
    escriu_solucions(nombres,s,escollit,suma_parcial);
    escollit.pop_back();
  }
}

void escriu_solucions (const vector<int>& nombres, int s){ 
  vector<bool> escollit;
  int suma_parcial = 0;
  escriu_solucions(nombres, s, escollit, suma_parcial);
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
