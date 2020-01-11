/*
ID: emadpres1
TASK: namenum
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 2: A,B,C     5: J,K,L    8: T,U,V
// 3: D,E,F     6: M,N,O    9: W,X,Y
// 4: G,H,I     7: P,R,S

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");

    string inp;
    fin >> inp;

    bool found = false;
    string dword, dword_num;
    ifstream dict_in("dict.txt");
    while(!dict_in.eof())
    {
        dict_in >> dword;
        dword_num = "";
        for(char c: dword)
        {
            if(c>'Q')
             c -= 1;
            dword_num += char('0'+(((c-'A')/3)+2));
        }

        if(dword_num==inp)
        {
            found=true;
            fout << dword <<endl;
        }
    }
    
    if(!found)
        fout << "NONE\n";
    return 0;
}