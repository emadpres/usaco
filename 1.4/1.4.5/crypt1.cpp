/*
ID: emadpres1
TASK: crypt1
LANG: C++                 
*/

// Note: This code is correct, but too generic for this simple problem.
//       Better idea is to just consider all 3-digit x 2-diti mulriplications in a nested loop and check their validity.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void convertBase(int num, int base, int res[], int l)
{
    while(l-->0) res[l-1]=0;

    int i=0;
    while(num >= base)
    {
        res[i++] = num % base;
        num /= base;
    }
    res[i] = num;
}

int convertIndexToNum(int index[], int l, int set[])
{
    int res = 0;
    for(int i=0; i<l; i++)
        res = res*10 + set[index[i]];
    return res;
}

bool CheckAllDigitsBelongToSet(int n, bool validDigits[])
{
    while(n>0)
    {
        int r = n%10;
        if(validDigits[r]==false) return false;
        n /= 10;
    }
    return true;
}

bool CheckNumberOfDigit(int n, int l)
{
    while(l-->0 && n>0)
        n /= 10;
    if(n>0) return false;

    return true;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");

    int digitSet[9], nDigits;
    bool validDigits[10] = {};
    fin >> nDigits;
    for(int i=0; i<nDigits; i++)
    {
        fin>>digitSet[i];
        validDigits[digitSet[i]]=true;
    }

    /*  A[2]  A[1]  A[0]
        x     B[1]  B[0]
        ----------------
    */
    int A[3]={0,0,0}, B[2]={0,0}; // A[i]: Index-to-digitSet-array for i-th digit of first number (i=0 for the right most digit)
    int nTotalValidResults = 0;
    for(int a=0; a< nDigits*nDigits*nDigits; a++)
    {
        convertBase(a, nDigits, A, 3);
        int aNum = convertIndexToNum(A, 3, digitSet);

        for(int b=0; b< nDigits*nDigits; b++)
        {
            convertBase(b, nDigits, B, 2);
            int bNum = convertIndexToNum(B, 2, digitSet);
            

            int p1 = aNum * (bNum%10);
            int p2 = aNum * (bNum/10);
            int mult = aNum * bNum;

            if(CheckNumberOfDigit(p1,3) && CheckNumberOfDigit(p2,3) && CheckNumberOfDigit(mult,4) &&
            CheckAllDigitsBelongToSet(p1,validDigits) && CheckAllDigitsBelongToSet(p2,validDigits) &&
            CheckAllDigitsBelongToSet(mult,validDigits))
        {
                nTotalValidResults++;
                //fout << aNum << " x " << bNum << " = "<< aNum*bNum << "\tAccepted #"<<nTotalValidResults <<endl;
            }


        }
    }

    fout << nTotalValidResults << endl;
    return 0;
}