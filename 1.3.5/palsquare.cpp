/*
ID: emadpres1
TASK: palsquare
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool IsPar(string s)
{
    int i=0, j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

string ChangeBase(int num, int base)
{
    string result = "";
    while(num>=base){
        int r = num%base;
        if(r>=10)
            result += char('A'+r-10);
        else
            result += char('0'+r);
        num /= base;
    }

    if(num>=10)
        result += char('A'+num-10);
    else
        result += char('0'+num);
    
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    fin >> base;

    for(int i=1; i<=300; i++)
    {
        int sq = i*i;

        if( IsPar(ChangeBase(sq, base)) )
            fout << ChangeBase(i, base)<<" "<<ChangeBase(sq, base)<<endl;
    }
    
    return 0;
}