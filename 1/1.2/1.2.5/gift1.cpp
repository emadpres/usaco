/*
ID: emadpre2
TASK: gift1
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    const int NP_MAX = 10;
    string names[NP_MAX];
    int NP, bank[NP_MAX];
    map<string, int> names2index;

    fin >> NP;
    for (int i = 0; i < NP; i++) {
        fin >> names[i];
        bank[i] = 0;
        names2index[names[i]] = i;
    }

    for (int i = 0; i < NP; i++) {
        string temp;
        int amount, nShare;
        fin >> temp >> amount >> nShare;
        if(0==nShare) continue;
        int share = amount/nShare;
        bank[names2index[temp]] -= share*nShare;
        while(nShare--) {
            fin >> temp;
            bank[names2index[temp]] += share;
        }
    }

    for(int i=0; i<NP; i++)
        fout << names[i] << " " << bank[names2index[names[i]]] << endl;
    
    
    return 0;
}