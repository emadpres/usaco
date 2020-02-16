/*
ID: emadpres1
TASK: numtri
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int& GetValue(int numbers[], int i, int j)
{
    // first number in i-th: 1+2+3+4+i at index i*(i+1)/2
    return numbers[ (i*(i+1)/2) + j];
}

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");

    const int MAX_LENGTH = 1000*1001/2;
    int nRow, length, numbers[MAX_LENGTH];
    fin >> nRow;
    length = (nRow*(nRow+1))/2;
    for (int i = 0; i < length; i++)
        fin >> numbers[i];

    for(int i=nRow-2; i>=0 ; i--)
        for(int j=i; j>=0; j--)
            GetValue(numbers, i, j) += max(GetValue(numbers, i+1, j), GetValue(numbers, i+1, j+1));
    
    fout << numbers[0] << endl;
    fin.close();
    fout.close();
    return 0;
}