/*
ID: emadpres1
TASK: ariprog
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_M = 250, MAX_BISQUARE = 2 * (MAX_M * MAX_M);

void FindAllBisquares(bool isBisquare[], int M)
{
    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= M; j++)
            isBisquare[i * i + j * j] = true;
}

int main()
{
    ofstream fout("ariprog.out");
    ifstream fin("ariprog.in");

    int N, M;
    fin >> N >> M;

    int maxBiSquare = 2 * (M * M);

    bool isBisquare[MAX_BISQUARE + 1] = {};
    FindAllBisquares(isBisquare, M);

    bool found = false;
    int b_end = 1;
    if(N>1)
        b_end = maxBiSquare / (N - 1);

    for (int b = 1; b <= b_end; b++)
    {
        for (int a = 0; a <= maxBiSquare-((N-1)*b); a++)
        {
            if(!isBisquare[a]) continue;
            
            bool valid = true;
            for (int n = 1; n < N && valid; n++)
            {
                if( a + n * b > MAX_BISQUARE   || 
                    isBisquare[a + n * b] == false)
                    valid  = false;
            }

            if (valid)
            {
                fout << a << " " << b << endl;
                found = true;
            }
        }
    }
    
    if (!found)
        fout << "NONE" << endl;
    fin.close();
    fout.close();
    return 0;
}