#include <iostream>
#include <vector>
using namespace std;


void write_words(const vector<string>& words, vector<bool>& used, vector<int>& sol) {
    if ( sol.size () == words. size ()){
        for (int idx : sol ) cout << words[idx];
        cout << endl;
    }
    else {
        for (uint i = 0; i < words.size (); ++i) {
            if (not used[ i ] and (sol.size () == 0 or words[sol.back ()].back () != words[i ][0])) {
                used[ i ] = true;
                sol.push_back( i );
                write_words(words,used, sol );
                sol.pop_back ();
                used[ i ] = false ;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    vector<bool> used(words.size(),false);
    vector<int> sol;
    for (int i=0; i<n; ++i) cin >> words[i];
    write_words(words,used, sol );
}