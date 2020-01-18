/*
ID: emadpres1
TASK: barn1
LANG: C++                 
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    const int N_STALL_MAX = 200;
    int maxBoard, nStall, nCow;
    bool stalls[N_STALL_MAX] = {}, covered[N_STALL_MAX] = {};
    
    fin >> maxBoard >> nStall >> nCow;
    int first=nStall, last=-1;
    for (int i = 0; i < nCow; i++)
    {
        int t;
        fin >> t;
        stalls[t-1] = true;
        if(t-1<first)
            first = t-1;
        if(t-1>last)
            last = t-1;
    }

    // Use one coard to cover all
    for (int i = first; i <= last; i++)
        covered[i] = true;
    
    int usedBoard = 1;
    while(usedBoard++<maxBoard)
    {
        // state = 0: looking for start of unneccesary covered empty stall,
        // state = 1: counting unneccesary covered countinous empty stalls
        int state = 0;
        int max_s=-1, max_e=-3;
        int cur_s=-1, cur = first;
        while (cur<=last)
        {
            if(state==0 && stalls[cur]==false && covered[cur]==true)
            {
                state = 1;
                cur_s = cur;
            }
            else if(state==1 && stalls[cur]==true)
            {
                int l = cur - cur_s;
                if(l > (max_e-max_s+1))
                {
                    max_s = cur_s;
                    max_e = cur-1;
                }
                state = 0;
            }
            cur++;
        }

        for(int i=max_s; i<=max_e; i++)
            covered[i]  = false;

    }

    int totalCovered = 0;
    for(int i=first; i<=last; i++)
        if(covered[i]) totalCovered++;

    fout << totalCovered << endl;
    
    
    return 0;
}