/*
ID: emadpres1
TASK: beads
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    const int MAX_N = 350;
    int N;
    char beads[MAX_N*2]; // we save two copy in row
 
    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> beads[i];
        beads[N+i] = beads[i];
    }

    int best = 0;
    for(int i=0; i<N; i++)
    {
        int cur = i;
        char c = beads[cur];
        int nColorChange = 2;
        if(c=='w')
            nColorChange = 3;
        
        while(nColorChange>0)
        {
            while(cur<N+i && (beads[cur]=='w' || beads[cur]==c))
                cur++;
            nColorChange--;
            c = beads[cur];
        }

        if(best < cur-i)
            best = cur-i;
    }

    fout << best << endl;
    

    return 0;
}