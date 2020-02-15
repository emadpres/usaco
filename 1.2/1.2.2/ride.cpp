/*
ID: emadpre2
TASK: ride
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    string x,y;
    fin >> x >> y;

    int mulx = 1 , muly=1;
    for(int i=0; i<x.length(); i++)
        mulx *= (int(x[i])-'A'+1);
    for(int i=0; i<y.length(); i++)
        muly *= (int(y[i])-'A'+1);

    if( (mulx%47) == (muly%47) )
        fout << "GO\n";
    else
        fout << "STAY\n";

    return 0;
}