/*
ID: emadpres1
TASK: sprime
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int targetLen;
vector<int> res;

bool IsPrime(int num)
{
    if(num<2) return false;
    for(int i=2; i*i<=num; i++)
        if(num%i==0)
            return false;
    return true;
}

// Assmution: num is prime or zero-length
void GenerateSuperPrimeForLength(int num, int curLen)
{
    if(curLen==targetLen){
        res.push_back(num);
        return;
    }

    int newNum;
    for (int i = 0; i <= 9; i++)
    {
        newNum = num*10+i;
        if(IsPrime(newNum))
            GenerateSuperPrimeForLength(newNum,curLen+1);
    }
    
}

int main() {
    ofstream fout ("sprime.out");
    ifstream fin ("sprime.in");
    
    fin >> targetLen;
    GenerateSuperPrimeForLength(0,0);

    sort(res.begin(), res.end());
    for(const int& v: res)
        fout <<v<<"\n";

    fin.close();
    fout.close();
    return 0;
}