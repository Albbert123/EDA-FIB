#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int lletra2idx (char c, const vector<char>& lletres)  {

  for (uint i = 0; i < lletres.size(); ++i)
    if (lletres[i] == c) return i;

  assert(false);
  return -1;
}

void  escriu_permutacions(const vector<char>& lletres, const vector<vector<bool>>& compatible,  vector<bool>& usada, vector<int>& sol) {

  // CAS BASE
  if (sol.size() == lletres.size()) {
    for (int idx : sol) cout << lletres[idx];
    cout << endl;
  }
  else {// CAS  RECURSIU
    for (uint i = 0; i < lletres.size(); ++i) {
      if (not usada[i] and (sol.empty() or compatible[sol.back()][i] )) {
	usada[i] = true;
	sol.push_back(i);
	escriu_permutacions(lletres,compatible,usada,sol);
	sol.pop_back();
	usada[i] = false;
      }
    }
  }
}


int main ( ){
  int n;
  cin >> n;
  vector<char> lletres(n);
  for (char& c : lletres) cin >> c;
  int m;
  cin >> m;
  vector<vector<bool>> compatible(n,vector<bool>(n,true));
  for (int  i = 0; i <m; ++i){
    char c1, c2;
    cin >> c1 >> c2;
    int idx1 = lletra2idx(c1,lletres);
    int idx2 = lletra2idx(c2,lletres); 
    compatible[idx1][idx2] = false;
    compatible[idx2][idx1] = false;   
  }

  vector<bool> usada(n,false);
  vector<int> sol;
  escriu_permutacions(lletres, compatible, usada, sol);
}
