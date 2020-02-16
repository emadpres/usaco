/*
ID: emadpres1
TASK: dualpal
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int N,S;
    fin >> N >> S;
    int nFound = 0, curNum = S+1;
    while(nFound<N)
    {
        int nPalFound = 0;
        for(int base=2; base<=10 && nPalFound<2; base++)
        {
            if(IsPar(ChangeBase(curNum, base)))
                nPalFound++;
        }
        if(nPalFound==2)
        {
            nFound++;
            fout << curNum <<endl;
        }
        curNum++;
    }
    
    return 0;
}