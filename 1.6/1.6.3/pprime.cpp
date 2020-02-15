/*
ID: emadpres1
TASK: pprime
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int a, b;
vector<int> res;

bool IsPrime(int num)
{
    for(int i=2; i*i<=num; i++)
        if(num%i==0)
            return false;
    return true;
}

void Expand(int num, int nDigits)
{
    if(num>b || nDigits>9 /*to stop ..00000.. goes wild*/) return;

    if(num>=a && IsPrime(num)) 
        res.push_back(num);

    int newNum;
    
    for(int i=0; i<=9; i++)
    {
        newNum = (i*pow(10, nDigits+1)) + (num*10) + i;
        Expand(newNum, nDigits+2);
    }
}


int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    
    fin >> a >> b;
    
    Expand(0,0);
    for(int i=0;i<=9;i++)
        Expand(i,1);

    sort(res.begin(), res.end());
    for(const int& v: res)
        fout <<v<<"\n";
        
    fin.close();
    fout.close();
    return 0;
}